#include "ip.h"
#include "arp.h"
#include "icmp.h"
#include "udp.h"
#include <string.h>


/**
 * @brief 处理一个收到的数据包
 *        你首先需要做报头检查，检查项包括：版本号、总长度、首部长度等。
 * 
 *        接着，计算头部校验和，注意：需要先把头部校验和字段缓存起来，再将校验和字段清零，
 *        调用checksum16()函数计算头部检验和，比较计算的结果与之前缓存的校验和是否一致，
 *        如果不一致，则不处理该数据报。
 * 
 *        检查收到的数据包的目的IP地址是否为本机的IP地址，只处理目的IP为本机的数据报。
 * 
 *        检查IP报头的协议字段：
 *        如果是ICMP协议，则去掉IP头部，发送给ICMP协议层处理
 *        如果是UDP协议，则去掉IP头部，发送给UDP协议层处理
 *        如果是本实验中不支持的其他协议，则需要调用icmp_unreachable()函数回送一个ICMP协议不可达的报文。
 *          
 * @param buf 要处理的包
 */
void ip_in(buf_t *buf)
{
    // TODO
    ip_hdr_t *ip_in_header = (ip_hdr_t *)buf->data;
    //报头检查：版本号、总长度、首部长度
    if ((ip_in_header->version != IP_VERSION_4) || ip_in_header->hdr_len * IP_HDR_LEN_PER_BYTE != sizeof(ip_hdr_t) || ip_in_header->total_len > 65535)
        return;
    //头部校验和
    uint16_t checkNumber = ip_in_header->hdr_checksum;
    uint16_t targetNumber = checksum16((uint16_t *)ip_in_header, sizeof(ip_hdr_t));
    ip_in_header->hdr_checksum = 0;
    if (targetNumber != checkNumber)
    {
        ip_in_header->hdr_checksum = checkNumber;
        return;
    }
    ip_in_header->hdr_checksum = checkNumber;
    if (memcmp(ip_in_header->dest_ip, net_if_ip, NET_IP_LEN) == 0)
    {
        //检查IP报头的协议字段
        if ((ip_in_header->protocol) == NET_PROTOCOL_ICMP)
        {
            //如果是ICMP协议，则去掉IP头部，发送给ICMP协议层处理
            buf_remove_header(buf, (ip_in_header->hdr_len) * IP_HDR_LEN_PER_BYTE);
            icmp_in(buf, ip_in_header->src_ip);
        }
        else if ((ip_in_header->protocol) == NET_PROTOCOL_UDP)
        {
            //如果是UDP协议，则去掉IP头部，发送给UDP协议层处理
            buf_remove_header(buf, (ip_in_header->hdr_len) * IP_HDR_LEN_PER_BYTE);
            udp_in(buf, ip_in_header->src_ip);
        }
        else
        {
            //如果是本实验中不支持的其他协议，则需要调用icmp_unreachable()函数回送一个ICMP协议不可达的报文。
            icmp_unreachable(buf, ip_in_header->src_ip, ICMP_CODE_PROTOCOL_UNREACH);
        }
    }
}

/**
 * @brief 处理一个要发送的分片
 *        你需要调用buf_add_header增加IP数据报头部缓存空间。
 *        填写IP数据报头部字段。
 *        将checksum字段填0，再调用checksum16()函数计算校验和，并将计算后的结果填写到checksum字段中。
 *        将封装后的IP数据报发送到arp层。
 * 
 * @param buf 要发送的分片
 * @param ip 目标ip地址
 * @param protocol 上层协议
 * @param id 数据包id
 * @param offset 分片offset，必须被8整除
 * @param mf 分片mf标志，是否有下一个分片
 */
void ip_fragment_out(buf_t *buf, uint8_t *ip, net_protocol_t protocol, int id, uint16_t offset, int mf)
{
    // TODO
    // 你需要调用buf_add_header增加IP数据报头部缓存空间。
    buf_add_header(buf, sizeof(ip_hdr_t));
    // 填写IP数据报头部字段。
    ip_hdr_t *ip_fragment_out_header = (ip_hdr_t *)buf->data;

    ip_fragment_out_header->version = IP_VERSION_4;
    ip_fragment_out_header->hdr_len = 5;
    ip_fragment_out_header->tos = 0;
    ip_fragment_out_header->id = swap16(id);
    if(mf == 0){
        ip_fragment_out_header->total_len = swap16(buf->len);                               //总长度
    }
    else{
        ip_fragment_out_header->total_len = swap16(ETHERNET_MTU);                           //总长度  
    }
    ip_fragment_out_header->ttl = IP_DEFAULT_TTL;
    ip_fragment_out_header->flags_fragment = swap16(offset >> 3 | mf << 13);

    memcpy(ip_fragment_out_header->src_ip, net_if_ip, NET_IP_LEN);
    memcpy(ip_fragment_out_header->dest_ip, ip, NET_IP_LEN);
    ip_fragment_out_header->hdr_checksum = 0;
    ip_fragment_out_header->hdr_checksum = checksum16((uint16_t *)buf->data, ip_fragment_out_header->hdr_len * IP_HDR_LEN_PER_BYTE);
    arp_out(buf, ip, NET_PROTOCOL_IP);
}

/**
 * @brief 处理一个要发送的数据包
 *        你首先需要检查需要发送的IP数据报是否大于以太网帧的最大包长（1500字节 - ip包头长度）。
 *        
 *        如果超过，则需要分片发送。 
 *        分片步骤：
 *        （1）调用buf_init()函数初始化buf，长度为以太网帧的最大包长（1500字节 - ip包头头长度）
 *        （2）将数据报截断，每个截断后的包长度 = 以太网帧的最大包长，调用ip_fragment_out()函数发送出去
 *        （3）如果截断后最后的一个分片小于或等于以太网帧的最大包长，
 *             调用buf_init()函数初始化buf，长度为该分片大小，再调用ip_fragment_out()函数发送出去
 *             注意：最后一个分片的MF = 0
 *    
 *        如果没有超过以太网帧的最大包长，则直接调用调用ip_fragment_out()函数发送出去。
 * 
 * @param buf 要处理的包
 * @param ip 目标ip地址
 * @param protocol 上层协议
 */
void ip_out(buf_t *buf, uint8_t *ip, net_protocol_t protocol)
{
    // TODO
    int id = 0;
    int eth_max_len = ETHERNET_MTU - sizeof(ip_hdr_t);
    if (buf->len > eth_max_len)
    {
        buf_t tempBuf;
        buf_init(&tempBuf, eth_max_len);
        for (int i = 0; i < buf->len / eth_max_len; i++)
        {
            buf_init(&txbuf, eth_max_len);
            memcpy(txbuf.data, buf->data + i * eth_max_len, eth_max_len);
            if (i == buf->len / eth_max_len - 1 & !(buf->len % eth_max_len))
                ip_fragment_out(&txbuf, ip, protocol, id, i * eth_max_len / IP_HDR_OFFSET_PER_BYTE, 0);
            else
                ip_fragment_out(&txbuf, ip, protocol, id, i * eth_max_len / IP_HDR_OFFSET_PER_BYTE, 1);
        }
        if (buf->len % eth_max_len)
        {
            buf_init(&txbuf, buf->len % eth_max_len);
            memcpy(txbuf.data, buf->data + buf->len / eth_max_len * eth_max_len, buf->len % eth_max_len);
            ip_fragment_out(&txbuf, ip, protocol, id, buf->len / eth_max_len * eth_max_len / IP_HDR_OFFSET_PER_BYTE, 0);
        }
    }
    else
    {
        ip_fragment_out(buf, ip, protocol, id, 0, 0);
    }
}

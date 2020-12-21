#include "icmp.h"
#include "ip.h"
#include <string.h>
#include <stdio.h>

/**
 * @brief 处理一个收到的数据包
 *        你首先要检查buf长度是否小于icmp头部长度
 *        接着，查看该报文的ICMP类型是否为回显请求，
 *        如果是，则回送一个回显应答（ping应答），需要自行封装应答包。
 * 
 *        应答包封装如下：
 *        首先调用buf_init()函数初始化txbuf，然后封装报头和数据，
 *        数据部分可以拷贝来自接收到的回显请求报文中的数据。
 *        最后将封装好的ICMP报文发送到IP层。  
 * 
 * @param buf 要处理的数据包
 * @param src_ip 源ip地址
 */
void icmp_in(buf_t *buf, uint8_t *src_ip)
{
    // TODO
    if (sizeof(buf) < sizeof(icmp_hdr_t))
    {
        return;
    }

    icmp_hdr_t *icmp_header = (icmp_hdr_t *)buf->data;
    uint16_t temp_number = icmp_header->checksum;
    uint16_t check_number = checksum16((uint16_t *)icmp_header, buf->len);
    icmp_header->checksum = 0;
    if (temp_number != check_number)
    {
        return;
    }
    icmp_header->checksum = temp_number;
    //接着，查看该报文的ICMP类型是否为回显请求
    if (icmp_header->type == ICMP_TYPE_ECHO_REQUEST)
    {
        buf_init(&txbuf, buf->len);
        memcpy(txbuf.data, buf->data, buf->len);
        icmp_hdr_t *temp_header = (icmp_hdr_t *)(&txbuf)->data;
        temp_header->type = ICMP_TYPE_ECHO_REPLY;
        temp_header->code = 0;
        temp_header->id = icmp_header->id;
        temp_header->seq = icmp_header->seq;
        temp_header->checksum = 0;
        temp_header->checksum = checksum16((uint16_t *)temp_header, txbuf.len);
        ip_out(&txbuf, src_ip, NET_PROTOCOL_ICMP);
    }
}

/**
 * @brief 发送icmp不可达
 *        你需要首先调用buf_init初始化buf，长度为ICMP头部 + IP头部 + 原始IP数据报中的前8字节 
 *        填写ICMP报头首部，类型值为目的不可达
 *        填写校验和
 *        将封装好的ICMP数据报发送到IP层。
 * 
 * @param recv_buf 收到的ip数据包
 * @param src_ip 源ip地址
 * @param code icmp code，协议不可达或端口不可达
 */
void icmp_unreachable(buf_t *recv_buf, uint8_t *src_ip, icmp_code_t code)
{
    // TODO
    int total_len = sizeof(icmp_hdr_t) + sizeof(ip_hdr_t) + 8;
    buf_init(&txbuf, total_len);
    //设置ICMP报头
    icmp_hdr_t *icmp_unreachable_header = (icmp_hdr_t *)(&txbuf)->data;
    icmp_unreachable_header->type = ICMP_TYPE_UNREACH;
    icmp_unreachable_header->code = code;
    icmp_unreachable_header->id = swap16(00);
    icmp_unreachable_header->seq = swap16(00);
    icmp_unreachable_header->checksum = 0;
    memcpy(txbuf.data + sizeof(icmp_hdr_t), recv_buf->data, sizeof(ip_hdr_t) + 8);
    icmp_unreachable_header->checksum = checksum16((uint16_t *)icmp_unreachable_header, txbuf.len);
    ip_out(&txbuf, src_ip, NET_PROTOCOL_ICMP);
}
#include "icmp.h"
#include "ip.h"
#include <string.h>
#include <stdio.h>

/**
 * @brief 处理一个收到的数据包
 *        你首先要检查ICMP报头长度是否小于icmp头部长度
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
    if (buf->len < sizeof(icmp_hdr_t))
    {
        return;
    }
    icmp_hdr_t *icmp_in_header = (icmp_hdr_t *)buf->data;
    //需要先把头部校验和字段缓存起来
    uint16_t temp_sum = icmp_in_header->checksum;
    //再将校验和字段清零
    icmp_in_header->checksum = 0;
    //调用checksum16()函数计算头部检验和，比较计算的结果与之前缓存的校验和是否一致
    uint16_t check_sum = checksum16((uint16_t *)buf->data, buf->len);
    icmp_in_header->checksum = temp_sum;

    if (check_sum != temp_sum)
    {
        return;
    }

    if (icmp_in_header->type == ICMP_TYPE_ECHO_REQUEST)
    {
        //首先调用buf_init()函数初始化txbuf，
        buf_init(&txbuf, buf->len);
        //然后封装报头和数据，数据部分可以拷贝来自接收到的回显请求报文中的数据
        memcpy(txbuf.data, buf->data, buf->len);
        icmp_hdr_t *icmp_package_header = (icmp_hdr_t *)txbuf.data;
        icmp_package_header->type = 0;
        icmp_package_header->checksum = 0;
        icmp_package_header->code = 0;
        icmp_package_header->id = icmp_in_header->id;
        icmp_package_header->seq = icmp_in_header->seq;
        icmp_package_header->checksum = checksum16((uint16_t *)icmp_package_header, txbuf.len);
        
        //最后将封装好的ICMP报文发送到IP层
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
    buf_init(&txbuf, 8 + 20 + 8); //长度为ICMP头部 + IP头部 + 原始IP数据报中的前8字节
    //设置ICMP报头
    icmp_hdr_t *icmp_unreachable_header = (icmp_hdr_t *)(&txbuf)->data;
    icmp_unreachable_header->type = ICMP_TYPE_UNREACH;
    icmp_unreachable_header->code = code;
    icmp_unreachable_header->id = 0;
    icmp_unreachable_header->seq = 0;
    icmp_unreachable_header->checksum = 0;

    memcpy(txbuf.data + sizeof(icmp_hdr_t), recv_buf->data, sizeof(ip_hdr_t) + 8);
    icmp_unreachable_header->checksum = checksum16((uint16_t *)icmp_unreachable_header, txbuf.len);
    ip_out(&txbuf, src_ip, NET_PROTOCOL_ICMP);
}
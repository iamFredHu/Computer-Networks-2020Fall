#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <linux/if_ether.h>
#include <netinet/in.h>
#define BUFFER_MAX 2048
int main(int argc, char *argv[])
{
    int fd;
    int proto;
    int str_len;
    char buffer[BUFFER_MAX];

    char *ethernet_head;
    char *ip_head;
    unsigned char *p;
    unsigned char *f;

    if ((fd = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL))) < 0)
    {
        printf("error create raw socket\n");
        return -1;
    }

    while (1)
    {
        str_len = recvfrom(fd, buffer, 2048, 0, NULL, NULL);
        if (str_len < 42)
        {
            printf("error when recv msg \n");
            return -1;
        }

        ethernet_head = buffer;
        p = ethernet_head;
        printf("Dst MAC address: %.2x:%02x:%02x:%02x:%02x:%02x\n", p[6], p[7], p[8], p[9], p[10], p[11]);
        printf("Src MAC address: %.2x:%02x:%02x:%02x:%02x:%02x\n", p[0], p[1], p[2], p[3], p[4], p[5]);

        f = ethernet_head + 12;
        printf("Type:%.2x%02x\n", f[0], f[1]);

        int choice = ((int)f[0] << 8) | (int)(f[1]);

        switch (choice)
        {
        case 0x0800:
            ip_head = ethernet_head + 14;
            p = ip_head;
            printf("Version:%d\n", p[0] >> 4);
            printf("Header length:%d\n", p[0] & 0xf);
            printf("Differentiated Services Field:0x%x\n", p[1]);
            printf("Total length:%d\n", ((int)p[2] << 8) + (int)p[3]);
            printf("Identification:0x%x\n", ((int)p[4] << 8) + (int)p[5]);
            printf("Flags:0x%x\n", (int)p[6] & 0xf0 >> 4);
            printf("Fragment Offset:0x%x\n", ((int)p[6] & 0xf << 8) + (int)p[7]);
            printf("LifeTime:0x%x\n", (int)p[8]);

            proto = p[9];
            printf("Protocol:");
            switch (proto)
            {
            case IPPROTO_ICMP:
                printf("icmp\n");
                break;
            case IPPROTO_TCP:
                printf("tcp\n");
                break;
            case IPPROTO_UDP:
                printf("udp\n");
                break;
            default:
                break;
            }

            int headerCheckSum = ((int)p[10] << 8) + (int)p[11];
            printf("Header Check Sum:0x%x\n", headerCheckSum);

            printf("Src IP:%d.%d.%d.%d\n", p[12], p[13], p[14], p[15]);
            printf("Dst IP:%d.%d.%d.%d\n", p[16], p[17], p[18], p[19]);

            break;
        case 0x0806:
            ip_head = ethernet_head + 14;
            p = ip_head;

            printf("Hardware type: 0x%x\n", ((int)p[0] << 8) + p[1]);
            printf("Protocol type: 0x%x\n", ((int)p[2] << 8) + p[3]);
            printf("Hardware size: 0x%x\n", (int)p[4]);
            printf("Protocol size: 0x%x\n", (int)p[5]);
            printf("Opcode: 0x%x\n", ((int)p[6] << 8) + p[7]);

            printf("Src MAC: %.2x:%02x:%02x:%02x:%02x:%02x\n", p[8], p[9], p[10], p[11], p[12], p[13]);
            printf("Src IP:  %d.%d.%d.%d\n", p[14], p[15], p[16], p[17]);
            printf("Dst MAC: %.2x:%02x:%02x:%02x:%02x:%02x\n", p[18], p[19], p[20], p[21], p[22], p[23]);
            printf("Dst IP:  %d.%d.%d.%d\n", p[24], p[25], p[26], p[27]);
            break;
        default:
            break;
        }
    }
    return -1;
}
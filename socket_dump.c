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
    int hardwareType, protocolType, hardwareSize, protocolSize, opCode;

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

        int choice = ((int)f[0] << 8) + (int)(f[1]);

        switch (choice)
        {
        case 0x0800:
            ip_head = ethernet_head + 14;
            p = ip_head;

            int v = p[0] >> 4;
            printf("Version:%d\n", v);

            int len = p[0] & 0xf;
            printf("Header length:%d\n", len);

            int DSF = p[1];
            printf("Differentiated Services Field:0x%x\n", DSF);

            int totalLen = ((int)p[2] << 8) + (int)p[3];
            printf("Total length:%d\n", totalLen);

            int identification = ((int)p[4] << 8) + (int)p[5];
            printf("Identification:0x%x\n", identification);

            int flags = (int)p[6] & 0xf0 >> 4;
            printf("Flags:0x%x\n", flags);

            int fragmentOffset = ((int)p[6] & 0xf << 8) + (int)p[7];
            printf("Fragment Offset:0x%x\n", fragmentOffset);

            int lifeTime = (int)p[8];
            printf("LifeTime:0x%x\n", lifeTime);

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

            hardwareType = ((int)p[0] << 8) + p[1];
            printf("Hardware type: 0x%x\n", hardwareType);

            protocolType = ((int)p[2] << 8) + p[3];
            printf("Protocol type: 0x%x\n", protocolType);

            hardwareSize = (int)p[4];
            printf("Hardware size: 0x%x\n", hardwareSize);

            protocolSize = (int)p[5];
            printf("Protocol size: 0x%x\n", protocolSize);

            opCode = ((int)p[6] << 8) + p[7];
            printf("Opcode: 0x%x\n", opCode);

            printf("Sender Mac address: %.2x:%02x:%02x:%02x:%02x:%02x\n", p[8], p[9], p[10], p[11], p[12], p[13]);
            printf("Sender IP address:  %d.%d.%d.%d\n", p[14], p[15], p[16], p[17]);
            printf("Target MAC address: %.2x:%02x:%02x:%02x:%02x:%02x\n", p[18], p[19], p[20], p[21], p[22], p[23]);
            printf("Target IP address:  %d.%d.%d.%d\n", p[24], p[25], p[26], p[27]);
            break;
        case 0x0835:
            ip_head = ethernet_head + 14;
            p = ip_head;

            hardwareType = ((int)p[0] << 8) + p[1];
            printf("Hardware type: 0x%x\n", hardwareType);

            protocolType = ((int)p[2] << 8) + p[3];
            printf("Protocol type: 0x%x\n", protocolType);

            hardwareSize = (int)p[4];
            printf("Hardware size: 0x%x\n", hardwareSize);

            protocolSize = (int)p[5];
            printf("Protocol size: 0x%x\n", protocolSize);

            int Op = ((int)p[6] << 8) + p[7];
            printf("Opcode: 0x%x\n", Op);

            printf("Sender Mac address: %.2x:%02x:%02x:%02x:%02x:%02x\n", p[8], p[9], p[10], p[11], p[12], p[13]);
            printf("Sender IP address: %d.%d.%d.%d\n", p[14], p[15], p[16], p[17]);
            printf("Target MAC address: %.2x:%02x:%02x:%02x:%02x:%02x\n", p[18], p[19], p[20], p[21], p[22], p[23]);
            printf("Target IP address: %d.%d.%d.%d\n", p[24], p[25], p[26], p[27]);
            break;
        default:
            printf("Error\n");
            break;
        }
    }
    return -1;
}
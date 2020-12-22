#include <pcap.h>
#include <string.h>
#include <utils.h>
#include "config.h"
static pcap_t *pcap;
static pcap_dumper_t *pdump;
static char pcap_errbuf[PCAP_ERRBUF_SIZE];
extern FILE* pcap_in;
extern FILE* pcap_out;
extern FILE *control_flow;

int driver_open()
{
        pcap = pcap_fopen_offline(pcap_in,pcap_errbuf);
        if(pcap == NULL){
                fprintf(stderr,"pcap_open_offline() failed:%s\n",pcap_errbuf);
                return -1;
        }

        pdump = pcap_dump_fopen(pcap,pcap_out);
        if(pdump == NULL){
                fprintf(stderr,"pcap_dump_fopen() failed:%s\n", pcap_geterr(pcap));
                return -1;
        }

        fprintf(control_flow,"driver opened\n");
        return 0;
}

int driver_recv(buf_t *buf)
{
        struct pcap_pkthdr *pkt_hdr;
        const uint8_t *pkt_data;
        int ret = pcap_next_ex(pcap, &pkt_hdr, &pkt_data);
        if (ret == PCAP_ERROR_BREAK){
                // printf("meet end of file\n");
                return 0;
        }else if (ret == 1){
                buf_init(buf,pkt_hdr->len);
                memcpy(buf->data, pkt_data, pkt_hdr->len);
                return pkt_hdr->len;
        }else{
                fprintf(stderr, "Error in driver_recv: %s\n", pcap_geterr(pcap));
                return -1;
        }
}

int driver_send(buf_t *buf)
{
        struct pcap_pkthdr header;
        memset(&header.ts,0,sizeof(header.ts));
        header.caplen = buf->len;
        header.len = buf->len;
        pcap_dump((u_char *)pdump,&header,buf->data);
        return 0;
}

void driver_close()
{
        fprintf(control_flow,"\ndriver closed\n");
        pcap_dump_close(pdump);
        pcap_close(pcap);
}

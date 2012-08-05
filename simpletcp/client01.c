#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define LISTEN_PORT         9901

int main(int argc, char *argv[])
{
    int                 code;
    int                 sockfd;
    struct sockaddr_in  servaddr;
    char                buf[128+1] =  {0};

    if (argc != 2) {
        printf("Useage: %s data\n", argv[0]);
        return  -1;
    }

    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(LISTEN_PORT);
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd ==  - 1) return -1;

    code = connect(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr));
    if (code ==  - 1) return -2;

    code = write(sockfd, argv[1], strlen(argv[1]));

    code = read(sockfd, buf, sizeof(buf) - 1);

    printf("Response: [%s]\n", buf);

    close(sockfd);

    return 0;
}

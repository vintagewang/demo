#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define LISTEN_PORT         9901

char *str_to_upper(char *str)
{
    int len = strlen(str);

    while (len--) {
        if (islower(str[len]))
            str[len] = str[len] - 32;
    }

    return str;
}

int SetSockOpt(int sockfd)
{
    int             code;
    int             optval;
    struct linger   Linger = {0};

    /* default */
    Linger.l_onoff = 0;
    Linger.l_linger = 0;
    code = setsockopt(sockfd, SOL_SOCKET, SO_LINGER, (void *)&Linger, sizeof(Linger));
    if (code == -1) return -1;

    optval = 1;
    code = setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (void *)&optval, sizeof(optval));
    if (code == -1) return -1;

    optval = 0;
    code = setsockopt(sockfd, SOL_SOCKET, SO_KEEPALIVE, (void *)&optval, sizeof(optval));
    if (code == -1) return -1;

    return 0;
}

int main(int argc, char *argv[])
{
    int                 code;
    int                 listenfd, connfd;
    struct sockaddr_in  cliaddr, servaddr;
    socklen_t           clilen = sizeof(cliaddr);

    char                buf[128+1] =  {0};

    memset(&cliaddr, 0, sizeof(cliaddr));
    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(LISTEN_PORT);

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd ==  -1) {
        printf("socket error %d [%d] [%s]\n", listenfd, errno, strerror(errno));
        return -1;
    }

    code = SetSockOpt(listenfd);
    if (code ==  -1) {
        printf("SetSockOpt error %d [%d] [%s]\n", code, errno, strerror(errno));
        return -1;
    }

    code = bind(listenfd, (struct sockaddr*) &servaddr, sizeof(servaddr));
    if (code ==  -1) {
        printf("bind error %d [%d] [%s]\n", code, errno, strerror(errno));
        return -1;
    }

    code = listen(listenfd, 128);
    if (code ==  -1) {
        printf("listen error %d [%d] [%s]\n", code, errno, strerror(errno));
        return -1;
    }

    while (1) {
        clilen = sizeof(cliaddr);
        memset(buf, 0, sizeof(buf));
        connfd = accept(listenfd, (struct sockaddr*) &cliaddr, (socklen_t*) &cliaddr);
        if (connfd ==  - 1) return -4;

        code = read(connfd, buf, sizeof(buf) - 1);

        printf("%-3dReceive data: [%s]\n", connfd, buf);

        if (code > 0)
            code = write(connfd, str_to_upper(buf), strlen(buf));

        close(connfd);
    }

    return 0;
}

#include <sys/socket.h>
int getsockopt(int sockfd, int level, int optname, void *optval, socklen_t *optlen);
int setsockopt(int sockfd, int level, int optname, const void *optval, socklen_t optlen);
/* Both return: 0 if OK, -1 on error */

/* SNIPPETS */
union {
    int            i_val;
    long           l_val;
    struct linger  linger_val;
    struct timeval timeval_val;
} optval;
len = sizeof(optval);
getsockopt(fd, opt_level, opt_name, &optval, &len);

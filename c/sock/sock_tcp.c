#include <sys/socket.h>
int socket (int family, int type, int protocol);
/* Setting protocol to 0 is indicating to select the
   system's default for the given combination of family and type */
/* Returns: non-negative descriptor if OK, -1 on error */

/*
 * family       | Description
 * -------------|----------------------
 * AF_INET      | IPv4 protocols
 * AF_INET6     | IPv6 protocols
 * AF_LOCAL     | Unix domain protocols
 * AF_ROUTE     | Routing socket
 * AF_KEY       | Key socket
 */
/*
 * type           | Description
 * ---------------|------------------------
 * SOCK_STREAM    | stream socket
 * SOCK_DGRAM     | datagram socket
 * SOCK_SEQPACKET | sequenced packet socket
 * SOCK_RAW       | raw socket
 */

/*
 * protocol          | Description
 * ------------------|-------------------
 * IPPROTO_TCP TCP   | transport protocol
 * IPPROTO_UDP UDP   | transport protocol
 * IPPROTO_SCTP SCTP | transport protocol
 */


#include <sys/socket.h>
int bind (int sockfd, const struct sockaddr *myaddr, socklen_t addrlen);
// myaddr->sin_addr.s_addr = htonl(INADDR_ANY);
/* Returns: 0 if OK, -1 on error */

#include <sys/socket.h>
int listen (int sockfd, int backlog);
/* Returns: 0 if OK, -1 on error */

#include <sys/socket.h>
int accept (int sockfd, struct sockaddr *cliaddr, socklen_t *addrlen);
/* Returns: non-negative descriptor if OK, -1 on error */

#include <sys/socket.h>
int connect(int sockfd, const struct sockaddr *servaddr, socklen_t addrlen);
/* Returns: 0 if OK, -1 on error */


/* Inspect local and peer tuplets */
#include <sys/socket.h>
int getsockname(int sockfd, struct sockaddr *localaddr, socklen_t *addrlen);
int getpeername(int sockfd, struct sockaddr *peeraddr, socklen_t *addrlen);
/* Both return: 0 if OK, -1 on error */

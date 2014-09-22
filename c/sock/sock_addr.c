/* =============== IPv4 Socket Address Structure =============== */
#include <netinet/in.h>
struct in_addr {
    in_addr_t s_addr; /* 32-bit IPv4 address */
                      /* network byte ordered */
};
struct sockaddr_in {
//  uint8_t        sin_len;     /* length of structure (16) */
    sa_family_t    sin_family;  /* AF_INET */
    in_port_t      sin_port;    /* 16-bit TCP or UDP port number */
                                /* network byte ordered */
    struct in_addr sin_addr;    /* 32-bit IPv4 address */
                                /* network byte ordered */
    char           sin_zero[8]; /* unused */
};

/* =============== Generic Socket Address Structure =============== */
#include <sys/socket.h>
struct sockaddr {
    uint8_t     sa_len;
    sa_family_t sa_family;   /* address family: AF_xxx value */
    char        sa_data[14]; /* protocol-specific address */
};

struct sockaddr_storage {
    uint8_t ss_len;        /* length of this struct (implementation
                              dependent) */
    sa_family_t ss_family; /* address family: AF_xxx value */
/* implementation-dependent elements to provide:
 * a) alignment sufficient to fulfill the alignment requirements of
 *    all socket address types that the system supports.
 * b) enough storage to hold any type of socket address that the
 *    system supports.
 */
};


/* =============== Byte Ordering =============== */
#include <netinet/in.h>
uint16_t htons(uint16_t host16bitvalue);
uint32_t htonl(uint32_t host32bitvalue);
/* Both return: value in network byte order */
uint16_t ntohs(uint16_t net16bitvalue);
uint32_t ntohl(uint32_t net32bitvalue);
/* Both return: value in host byte order */


/* =============== Addr Converting =============== */
#include <arpa/inet.h>
int inet_aton(const char *strptr, struct in_addr *addrptr);
/* Returns: 1 if string was valid, 0 on error */
in_addr_t inet_addr(const char *strptr); // Deprecated
/* Returns: 32-bit binary network byte ordered IPv4 address; INADDR_NONE if error */
char *inet_ntoa(struct in_addr inaddr);
/* Returns: pointer to dotted-decimal string */

#include <arpa/inet.h>
int inet_pton(int family, const char *strptr, void *addrptr); // Preferred
/* Returns: 1 if OK, 0 if input not a valid presentation format, -1 on error */
const char *inet_ntop(int  family,  const void *addrptr,  char *strptr,  size_t  len); // Preferred
/* Returns: pointer to result if OK, NULL on error */
// family :: [AF_INET, AF_INET6]
// len :: [INET_ADDRSTRLEN(16), INET6_ADDRSTRLEN(46)] (netinet/in.h)

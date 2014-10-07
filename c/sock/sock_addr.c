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



/* =============== Name and Address Conversion =============== */
#include <netdb.h>
struct hostent *gethostbyname (const char *hostname);
/* Returns: non-null pointer if OK, NULL on error with h_errno set */

struct hostent {
    char  *h_name;      /* official (canonical) name of host */
    char **h_aliases;   /* pointer to array of pointers to alias names */
    int    h_addrtype;  /* host address type: AF_INET */
    int    h_length;    /* length of address: 4 */
    char **h_addr_list; /* ptr to array of ptrs with IPv4 addrs */
};

/* h_errno:
       - HOST_NOT_FOUND
       - TRY_AGAIN
       - NO_RECOVERY
       - NO_DATA (identical to NO_ADDRESS) */




#include <netdb.h>
int getaddrinfo (const char *hostname, const char *service,
                 const struct addrinfo *hints, struct addrinfo **result) ;
/* Returns: 0 if OK, nonzero on error */

struct addrinfo {
    int              ai_flags;     /* AI_PASSIVE, AI_CANONNAME */
    int              ai_family;    /* AF_xxx */
    int              ai_socktype;  /* SOCK_xxx */
    int              ai_protocol;  /* 0 or IPPROTO_xxx for IPv4 and IPv6 */
    socklen_t        ai_addrlen;   /* length of ai_addr */
    char            *ai_canonname; /* ptr to canonical name for host */
    struct sockaddr *ai_addr;      /* ptr to socket address structure */
    struct addrinfo *ai_next;      /* ptr to next structure in linked list */
};

/* The members of the hints structure that can be set by the caller are:
      - ai_flags    (zero or more AI_XXX values OR'ed together)
      - ai_family   (an AF_xxx value)
      - ai_socktype (a SOCK_xxx value)
      - ai_protocol */

/* ai_flags: [AI_PASSIVE,  AI_CANONNAME, AI_NUMERICHOST, AI_NUMERICSERV,
              AI_V4MAPPED, AI_ALL, AI_ADDRCONFIG]
*/


/* ====== Four types of network-related information =================== */

Info      | Data file      | Structure  | Keyed lookup functions
----------|----------------|------------|---------------------------------
Hosts     | /etc/hosts     | hostent    | gethostbyaddr,  gethostbyname
Networks  | /etc/networks  | netent     | getnetbyaddr,   getnetbyname
Protocols | /etc/protocols | protoent   | getprotobyname, getprotobynumber
Services  | /etc/services  | servent    | getservbyname,  getservbyport

#include <sys/select.h>
int select(int                      maxfdp1,
           fd_set *restrict         readfds,
           fd_set *restrict         writefds,
           fd_set *restrict         exceptfds,
           struct timeval *restrict tvptr);
/* Returns: count of ready descriptors, 0 on timeout, -1 on error */

struct timeval {
    long tv_sec;  /* seconds */
    long tv_usec; /* and microseconds */
};

#include <sys/select.h>
void FD_CLR(intfd,fd_set *fdset);    /* turn off the bit for fd in fdset */
void FD_SET(intfd,fd_set *fdset);    /* turn on the bit for fd in fdset */
void FD_ZERO(fd_set *fdset);         /* clear all bits in fdset */
int FD_ISSET(int fd, fd_set *fdset); /* is the bit for fd on in fdset ? */
/* FD_ISSET returns: nonzero if fd is in set, 0 otherwise */
/* After declaring a descriptor set, we must zero the set using FD_ZERO
   We then set bits in the set for each descriptor that we're interested in */


void FD_ZERO(fd_set *fdset);
void FD_SET(int fd, fd_set *fdset);
void FD_CLR(int fd, fd_set *fdset);
int FD_ISSET(int fd, fd_set *fdset);

#include <sys/select.h>
int pselect(int                             maxfdp1,
            fd_set *restrict                readfds,
            fd_set *restrict                writefds,
            fd_set *restrict                exceptfds,
            const struct timespec *restrict tsptr,
            const sigset_t *restrict        sigmask);
/* Returns: count of ready descriptors, 0 on timeout, -1 on error */


#include <poll.h>
int poll(struct pollfd fdarray[], nfds_t nfds, int timeout);
/* Returns: count of ready descriptors, 0 on timeout, -1 on error */

struct pollfd {
    int fd;        /* file descriptor to check, or <0 to ignore */
    short events;  /* events of interest on fd */
    short revents; /* events that occurred on fd */
};


#include <sys/uio.h>
ssize_t readv(int filedes, const struct iovec *iov, int iovcnt);
ssize_t writev(int filedes, const struct iovec *iov, int iovcnt);
/* Both return: number of bytes read or written, -1 onerror */

struct iovec {
    void   *iov_base; /* starting address of buffer */
    size_t iov_len;   /* size of buffer */
};



/* =============== Mapped Memory =============== */
#include <sys/mman.h>
void *mmap(void   *addr,
           size_t len,
           int    prot,
           int    flag,
           int    filedes,
           off_t  off );
/* Returns: starting address of mapped region if OK, MAP_FAILED on error */
/* We normally set addr argument to 0 to allow the system to choose the starting address */
/* prot can be set  as either PROT_NONE or the bitwise OR of
   any combination of [PROT_READ, PROT_WRITE, PROT_EXEC]
   The prot specified for a region can't allow more access than
   the open mode of the file */
/*
  flag         | Description
  -------------|----------------------------------------------
  MAP_SHARED   | store operations modify the mapped file
  MAP_PRIVATE  | store operations into the mapped region cause
               | a private copy of the mapped file
*/

/* Change the permissions on an existing mapping by calling mprotect */
#include <sys/mman.h>
int mprotect(void *addr, size_t len, int prot);
/* Returns: 0 if OK, -1 on error */

#include <sys/mman.h>
int msync(void *addr, size_t len, int flags);
// flags :: [MS_SYNC, MS_ASYNC]
/* Returns: 0 if OK, -1 on error */

/* Closing the file descriptor filedes does not unmap the region */
/* Call to munmap does not cause the contents of the mapped region to be written to the disk file */
#include <sys/mman.h>
int munmap(caddr_t addr, size_t len);
/* Returns: 0 if OK, -1 on error */

#include <sys/stat.h>

struct stat {
    mode_t    st_mode;    /* file type & mode (permissions) */
    ino_t     st_ino;     /* i-node number (serial number) */
    dev_t     st_dev;     /* device number (file system) */
    dev_t     st_rdev;    /* device number forspecial files */
    nlink_t   st_nlink;   /* number of links */
    uid_t     st_uid;     /* user ID of owner */
    gid_t     st_gid;     /* group ID of owner*/
    off_t     st_size;    /* size in bytes, for regular files */
    time_t    st_atime;   /* time of last access */
    time_t    st_mtime;   /* time of last modification */
    time_t    st_ctime;   /* time of last filestatus change */
    blksize_t st_blksize; /* best I/O block size */
    blkcnt_t  st_blocks;  /* number of disk blocks allocated */
};

int stat(const char *restrict pathname, struct stat*restrict buf);
int fstat(int filedes, struct stat *buf);
int lstat(const char *restrict pathname, struct stat *restrict buf);
/* All three return: 0 if OK, -1 on error */

/* File type macros in <sys/stat.h>
Macro              | Type of file
--------------------------------------------
S_ISREG(st_mode)   | regular file
S_ISDIR(st_mode)   | directory file
S_ISCHR(st_mode)   | character special file
S_ISBLK(st_mode)   | block special file
S_ISFIFO(st_mode)  | pipe or FIFO
S_ISLNK(st_mode)   | symbolic link
S_ISSOCK(st_mode)  | socket
*/

/* IPC type macros in <sys/stat.h>
Macro                 | Type of object
----------------------|---------------------
S_TYPEISMQ(st_mode)   | message queue
S_TYPEISSEM(st_mode)  | semaphore
S_TYPEISSHM(st_mode)  | shared memory object
*/

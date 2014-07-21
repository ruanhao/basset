#include <unistd.h>
/* Standard file descriptors.  */
#define	STDIN_FILENO	0	/* Standard input.  */
#define	STDOUT_FILENO	1	/* Standard output.  */
#define	STDERR_FILENO	2	/* Standard error output.  */


#include <fcntl.h>
/* Returns: file descriptor if OK, –1 on error */
int open(const char *pathname, int oflag, ... /* mode_t mode */ );
/*
oflag argument is formed by ORing together one or more of the following
constants from the <fcntl.h> header:

O_RDONLY   Open for reading only.
O_WRONLY   Open for writing only.
O_RDWR     Open for reading and writing

The following constants are optional:

O_APPEND   Append to the end of file on each write
O_CREAT    Create the file if it doesn't exist. This option requires a third argument to the open function, the
           mode, which specifies the access permission bits ofthe new file
O_EXCL     Generate an error if O_CREAT is also specified and the file already exists. This test for whether the
           file already exists and the creation of the file ifit doesn't exist is an atomic operation
O_TRUNC    If the file exists and if it is successfully opened for either write-only or read–write, truncate its
           length to 0
O_NOCTTY   If the pathname refers to a terminal device, do not allocate the device as the controlling terminal
           for this process
O_NONBLOCK If the pathname refers to a FIFO, a block special file, or a character special file, this option sets
           the nonblocking mode for both the opening of the file and subsequent I/O

The following three flags are also optional. They are part of the synchronized input and output optionof the
Single UNIX Specification (and thus POSIX.1):

O_DSYNC    Have each write wait for physical I/O to complete, but don't wait for file attributes to be updated if
           they don't affect the ability to read the data just written
O_RSYNC    Have each read operation on the file descriptor wait until any pending writes for the same portion of
           the file are complete
O_SYNC     Have each write wait for physical I/O to complete, including I/O necessary to update file attributes
           modified as a result of the write
*/
// Eg: open(pathname, O_WRONLY | O_CREAT | O_TRUNC, mode);

#include <unistd.h>
/* Returns: 0 if OK, –1 on error */
int close(int filedes);

#include <unistd.h>
/* Returns: new file offset if OK, –1 on error */
off_t lseek(int filedes, off_t offset, int whence); /* If whence is SEEK_SET, the file's offset is set to offset bytes from thebeginning of the file
                                                     * If whence is SEEK_CUR, the file's offset is set to its current value plus the offset
                                                       The offset can be positive or negative
                                                     * If whence is SEEK_END, the file's offset is set to the size of the file plus the offset
                                                       The offset can be positive or negative
                                                     */

#include <unistd.h>
/* Returns: number of bytes read, 0 if end of file, –1 on error */
ssize_t read(int filedes, void *buf, size_t nbytes);

#include <unistd.h>
/* Returns: number of bytes written if OK, –1 on error */
ssize_t write(int filedes, const void *buf, size_t nbytes);

#include <unistd.h>
/* The Single UNIX Specification includes XSI extensions that allow applications to seek and perform I/O ATOMICALLY
   These extensions are pread and pwrite: */
/* Returns: number of bytes read, 0 if end of file, –1 on error */
ssize_t pread(int filedes, void *buf, size_t nbytes, off_t offset);
/* Returns: number of bytes written if OK, –1 on error */
ssize_t pwrite(int filedes, const void *buf, size_t nbytes, off_t offset);

#include <unistd.h>
/* Both return: new file descriptor if OK, –1 on error */
int dup(int filedes);
int dup2(int filedes, int filedes2);

#include <unistd.h>
/* Returns: 0 if OK, –1 on error */
int fsync(int filedes);
int fdatasync(int filedes);
/* No return */
void sync(void);

#include <fcntl.h>
/* Returns: depends on cmd if OK, –1 on error */
int fcntl(int filedes, int cmd, ... /* int arg */ ); /*
                                                       The fcntlfunction is used for five different purposes:
                                                       1.  Duplicate an existing descriptor (cmd = F_DUPFD)
                                                       2.  Get/set file descriptor flags (cmd = F_GETFD or F_SETFD)
                                                       3.  Get/set file status flags (cmd = F_GETFL or F_SETFL)
                                                       4.  Get/set asynchronous I/O ownership (cmd = F_GETOWN or F_SETOWN)
                                                       5.  Get/set record locks (cmd = F_GETLK, F_SETLK, or F_SETLKW)
                                                     */

#include <sys/ioctl.h> /* BSD and Linux */
/* Returns: –1 on error, something else if OK */
int ioctl(int filedes, int request, ...);

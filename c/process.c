#include <stdlib.h>
void exit(int status);
void _Exit(int status);
#include <unistd.h>
void _exit(int status);

#include <stdlib.h>
int atexit(void (*func)(void));
/* Returns: 0 if OK, nonzero on error */

#include <stdlib.h>
void *malloc(size_t size);
void *calloc(size_t nobj, size_t size);
void *realloc(void *ptr, size_t newsize);
/* All three return: non-null pointer if OK, NULL on error */
void free(void *ptr);

#include <stdlib.h>
char *getenv(const char *name);
/* Returns: pointer to value associated with name, NULL if not found */

#include <stdlib.h>
int putenv(char *str);
int setenv(const char *name, const char *value, int rewrite);
int unsetenv(const char *name);
/* All return: 0 if OK, nonzero on error */

#include <setjmp.h>
int setjmp(jmp_buf env);
/* Returns: 0 if called directly, nonzero if returning from a call to longjmp */
void longjmp(jmp_buf env, int val);

#include <unistd.h>
pid_t getpid(void);
/* Returns: process ID of calling process */
pid_t getppid(void);
/* Returns: parent process ID of calling process */

#include <unistd.h>
pid_t fork(void);
/* Returns: 0 in child, process ID of child in parent,–1 on error */

#include <sys/wait.h>
pid_t wait(int *statloc);
pid_t waitpid(pid_t pid, int *statloc, int options);
/* Both return: process ID if OK, 0, or –1 on error */
/* POSIX.1 specifies that the termination status is to be looked at using various macros that are defined in <sys/wait.h>:
   WIFEXITED(status)   -> WEXITSTATUS(status)
   WIFSIGNALED(status) -> WTERMSIG(status)
   WIFSTOPPED(status)  -> WSTOPSIG(status)
   WIFCONTINUED(status)
 */
/*
The interpretation of the pid argument for waitpid depends on its value:
pid == –1  Waits for any child process. In this respect, waitpid is equivalent to wait
pid >   0  Waits for the child whose process ID equals pid
pid ==  0  Waits for any child whose process group ID equals that of the calling process
pid <  –1  Waits for any child whose process group ID equals the absolute value of pid
*/
/*
  options:
  WNOHANG -> The waitpid function will not block if
             a child specified by pid is not immediately available.
             In this case, the return value is 0.
 */

#include <sys/wait.h>
int waitid(idtype_t idtype, id_t id, siginfo_t *infop, int options);
/* Returns: 0 if OK, –1 on error */

/* The idtype constants for waitid
   Constant  Description
   P_PID     Wait for a particular process: id contains the process ID of the child to wait for
   P_PGID    Wait for any child process in a particular process group:
             id contains the process group ID of the children to wait for
   P_ALL     Wait for any child process: id is ignored
*/
/* The options constants for waitid
   Constant       Description
   WCONTINUED     Wait for a process that has previously stopped and has been continued,
                  and whose status has not yet been reported
   WEXITED        Wait for processes that have exited
   WNOHANG        Return immediately instead of blocking if there is no child exit status available
   WNOWAIT        Don't destroy the child exit status
                  The child's exit status can be retrieved by a subsequent call to wait, waitid,or waitpid
   WSTOPPED       Wait for a process that has stopped and whose status has not yet been reported
*/


#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>
pid_t wait3(int *statloc, int options, struct rusage *rusage);
pid_t wait4(pid_t pid, int *statloc, int options, struct rusage *rusage);
/* Both return: process ID if OK, 0, or –1 on error */

#include <unistd.h>
int execl(const char *pathname, const char *arg0, ... /* (char *)0 */ );
int execv(const char *pathname, char *const argv []);
int execle(const char *pathname, const char *arg0, ... /* (char *)0, char *const envp[] */ );
int execve(const char *pathname, char *const argv[], char *const envp []);
int execlp(const char *filename, const char *arg0, ... /* (char *)0 */ );
int execvp(const char *filename, char *const argv []);
/* All six return: –1 on error, no return on success */

#include <stdlib.h>
int system(const char *cmdstring);
/* 1. If either the fork fails or waitpid returns an error other than EINTR, system returns –1 with errnoset to indicate the error
   2. If the exec fails, implying that the shell can't be executed, the return value is as if the shell had executed exit(127)
   3.  Otherwise, all three functions (fork, exec, and waitpid) succeed, and the return value from system is the termination status of the shell
*/

#include <sys/times.h>
clock_t times(struct tms *buf);
/* Returns: elapsed wall clock time in clock ticks if OK, –1 on error */

struct tms {
    clock_t tms_utime;  /* user CPU time */
    clock_t tms_stime;  /* system CPU time */
    clock_t tms_cutime; /* user CPU time, terminated children */
    clock_t tms_cstime; /* system CPU time, terminated children */
};
/*
  Note that the structure does not contain any measurement for the wall clock time. Instead, the function returns the wall clock time as the value of the function, each time it's called.
  This value is measured from some arbitrary point in the past, so we can't use its absolute value; instead, we use its relative value.
  For example, we call timesand save the return value. At some later time, we call timesagain and subtract the earlier return value from the new return value. The difference is the wall clock time.
*/
/*
  All the clock_tvalues returned by this function are converted to seconds using the number of clock ticks per second—the _SC_CLK_TCK value returned by sysconf
  real_sec = (end - start) / (double) sysconf(_SC_CLK_TCK);
*/

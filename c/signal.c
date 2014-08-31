#define SIG_ERR (void (*)())-1
#define SIG_DFL (void (*)())0
#define SIG_IGN (void (*)())1


/* =========== Signal Handler =========== */
#include <signal.h>
void (*signal(int signo, void (*func)(int)))(int);
/* Returns: previous disposition of signal (see following) if OK, SIG_ERR on error */
/*
  The value of func is (a) the constant SIG_IGN
                       (b) the constant SIG_DFL
                       (c) the address of a function to be called when the signal occurs
  The return value from signalis the pointer to the previous signal handler
*/

#include <signal.h>
int sigaction(int signo, const struct sigaction *restrict act, struct sigaction *restrict oact);
/* Returns: 0 if OK, –1 on error */
struct sigaction {
    void (*sa_handler)(int); /* addr of signal handler, */
                             /* or SIG_IGN, or SIG_DFL */
    sigset_t sa_mask; /* additional signals to block */
                      /* operating system includes the signal being delivered
                         in the signal mask when the handler is invoked */
    int sa_flags; /* signal options */
    /* alternate handler */
    void (*sa_sigaction)(int, siginfo_t *, void *);
};

struct siginfo {
    int si_signo;  /* signal number */
    int si_errno;  /* if nonzero, errno value from <errno.h> */
    int si_code;   /* additional info (dependson signal) */
    pid_t si_pid;  /* sending process ID */
    uid_t si_uid;  /* sending process real user ID */
    void *si_addr; /* address that caused the fault */
    int si_status; /* exit value or signal number */
    long si_band;  /* band number for SIGPOLL */
    /* possibly other fields also */
};

/* Reliable version of signal(), using POSIX sigaction(). */
void (*signal(int signo, void (*func)(int)))(int) {
    struct sigaction act, oact;
    act.sa_handler = func;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    if (signo == SIGALRM) {
#ifdef SA_INTERRUPT
        act.sa_flags |= SA_INTERRUPT;
#endif
    } else {
#ifdef SA_RESTART
        act.sa_flags |= SA_RESTART;
#endif
    }
    if (sigaction(signo, &act, &oact) < 0)
        return(SIG_ERR);
    return(oact.sa_handler);
}





/* =========== Signal Generate =========== */
#include <signal.h>
int kill(pid_t pid, int signo);
int raise(int signo);
/* Both return: 0 if OK, –1 on error */

#include <unistd.h>
unsigned int alarm(unsigned int seconds);
/* Returns: 0 or number of seconds until previously set alarm */





/* =========== Signal Waiting =========== */
#include <unistd.h>
int pause(void);
/* Returns: –1 with errnoset to EINTR */

#include <signal.h>
int sigsuspend(const sigset_t *sigmask);
/* Returns: –1 with errnoset to EINTR */





/* =========== Process Signal Mask =========== */
#include <signal.h>
int sigemptyset(sigset_t *set);
int sigfillset(sigset_t *set);
int sigaddset(sigset_t *set, int signo);
int sigdelset(sigset_t *set, int signo);
/* All four return: 0 if OK, –1 on error */
int sigismember(const sigset_t *set, int signo);
/* Returns: 1 if true, 0 if false, –1 on error */

#include <signal.h>
int sigprocmask(int how, const sigset_t *restrict set, sigset_t *restrict oset);
/* Returns: 0 if OK, –1 on error */
/*
How          |  Description
-------------|-----------------------------------------------------------------------------------------
SIG_BLOCK    |  The new signal mask for the process is the union ofits current signal mask and
             |  the signal set pointed to by set.
             |  That is, set contains the additional signals that we want to block.
SIG_UNBLOCK  |  The new signal mask for the process is the intersection of its current signal mask and
             |  the complement of the signal set pointed to by set.
             |  That is, set contains the signals that we want to unblock.
SIG_SETMASK  |  The new signal mask for the process is replaced by
             |  the value of the signal set pointed to by set.
*/





/* =========== Signal Utils =========== */
#include <setjmp.h>
int sigsetjmp(sigjmp_buf env, int savemask);
/* Returns: 0 if called directly, nonzero if returning from a call to siglongjmp */
void siglongjmp(sigjmp_buf env, int val);

#include <signal.h>
int sigpending(sigset_t *set);
/* Returns: 0 if OK, –1 on error */

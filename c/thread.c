/* ============== Thread Info ============== */
#include <pthread.h>
int pthread_equal(pthread_t tid1, pthread_t tid2);
/* Returns: nonzero if equal, 0 otherwise */

#include <pthread.h>
pthread_t pthread_self(void);
/* Returns: the thread ID of the calling thread */




/* ============== Thread Create ============== */
#include <pthread.h>
int pthread_create(pthread_t *restrict tidp, const pthread_attr_t *restrict attr,
                   void *(*start_rtn)(void *), void *restrict arg);
/* Returns: 0 if OK, error number on failure */

#include <pthread.h>
int pthread_detach(pthread_t tid);
/* Returns: 0 if OK, error number on failure */




/* ============== Thread Terminate ============== */
/*
  A single thread can exit in three ways:
  1. The thread can simply return from the start routine. The return value is the thread's exit code.
  2. The thread can be canceled by another thread in the same process.
  3. The thread can call pthread_exit.
*/
#include <pthread.h>
void pthread_exit(void *rval_ptr);
/* The rval_ptr is a typeless pointer, similar to the single argument passed to the start routine.
   This pointer is available to other threads in the process by calling the pthread_join function: */
#include <pthread.h>
int pthread_join(pthread_t thread, void **rval_ptr);
/* Returns: 0 if OK, error number on failure */

#include <pthread.h>
int pthread_cancel(pthread_t tid);
/* Returns: 0 if OK, error number on failure */




/* ============== Thread Cleanup ============== */
#include <pthread.h>
void pthread_cleanup_push(void (*rtn)(void *), void *arg);
void pthread_cleanup_pop(int execute);
/* Cleanup function is to be called when the thread performs one of the following actions:
   1, Makes a call to pthread_exit
   2, Responds to a cancellation request
   3, Makes a call to pthread_cleanup_pop with a nonzero execute argument */
/* THESE TWO FUNCTIONS MUST BE USED IN MATCHED PAIRS WITHIN THE SAME SCOPE IN A THREAD */




/* ============== Thread Synchronize ============== */
/* Mutex */
#include <pthread.h>
int pthread_mutex_init(pthread_mutex_t *restrict mutex, const pthread_mutexattr_t *restrict attr);
// pthread_mutex_t pmutex = PTHREAD_MUTEX_INITIALIZER;
int pthread_mutex_destroy(pthread_mutex_t *mutex);
/* Both return: 0 if OK, error number on failure */

#include <pthread.h>
int pthread_mutex_lock(pthread_mutex_t *mutex);
int pthread_mutex_trylock(pthread_mutex_t *mutex);
int pthread_mutex_unlock(pthread_mutex_t *mutex);
/* All return: 0 if OK, error number on failure */

/* RwLock */
#include <pthread.h>
int pthread_rwlock_init(pthread_rwlock_t *restrict rwlock, const pthread_rwlockattr_t *restrict attr);
// pthread_rwlock_t prwl = PTHREAD_RWLOCK_INITIALIZER;
int pthread_rwlock_destroy(pthread_rwlock_t *rwlock);
/* Both return: 0 if OK, error number on failure */

#include <pthread.h>
int pthread_rwlock_rdlock(pthread_rwlock_t *rwlock);
int pthread_rwlock_wrlock(pthread_rwlock_t *rwlock);
int pthread_rwlock_unlock(pthread_rwlock_t *rwlock);
/* All return: 0 if OK, error number on failure */

#include <pthread.h>
int pthread_rwlock_tryrdlock(pthread_rwlock_t *rwlock);
int pthread_rwlock_trywrlock(pthread_rwlock_t *rwlock);
/* Both return: 0 if OK, error number on failure */

/* Condition Variables */
#include <pthread.h>
int pthread_cond_init(pthread_cond_t *restrict cond, pthread_condattr_t *restrict attr);
// pthread_cond_t pcond = PTHREAD_COND_INITIALIZER;
int pthread_cond_destroy(pthread_cond_t *cond);
/* Both return: 0 if OK, error number on failure */

#include <pthread.h>
int pthread_cond_wait(pthread_cond_t *restrict cond, pthread_mutex_t *restrict mutex);
int pthread_cond_timedwait(pthread_cond_t *restrict cond, pthread_mutex_t *restrict mutex,
                           const struct timespec *restrict timeout);
/* Both return: 0 if OK, error number on failure */

struct timespec {
    time_t tv_sec;   /* seconds     */
    long   tv_nsec;  /* nanoseconds */
};

/* Use 'gettimeofday' to get the current time expressed as a timeval structure and
   translate this into a timespec structure.
   We can use the following function: */
void maketimeout(struct timespec *tsp, long minutes) {
    struct timeval now;
    /* get the current time */
    gettimeofday(&now);
    tsp->tv_sec = now.tv_sec;
    tsp->tv_nsec = now.tv_usec * 1000; /* usec to nsec */
    /* add the offset to get timeout value */
    tsp->tv_sec += minutes * 60;
}

#include <pthread.h>
int pthread_cond_signal(pthread_cond_t *cond);
int pthread_cond_broadcast(pthread_cond_t *cond);
/* Both return: 0 if OK, error number on failure */





/*
 * THREAD CONTROL
 */

/* ============== Thread Attributes ============== */

#include <pthread.h>
int pthread_attr_init(pthread_attr_t *attr);
int pthread_attr_destroy(pthread_attr_t *attr);
/* Both return: 0 if OK, error number on failure */


/* POSIX.1 thread attributes: (represented by pthread_attr_t structure)
 * Name        |  Description
 * ------------|---------------------------------------------------
 * detachstate |  detached thread attribute
 * guardsize   |  guard buffer size in bytes at end of thread stack
 * stackaddr   |  lowest address of thread stack
 * stacksize   |  size in bytes of thread stack
 */

/*
 * Other attributes not represented by pthread_attr_t structure:
 * 1, cancelability state
 * 2, cancelability type
 * 3, concurrency level
 */


/* Set detachstate */
#include <pthread.h>
int pthread_attr_getdetachstate(const pthread_attr_t *restrict attr, int *detachstate);
int pthread_attr_setdetachstate(pthread_attr_t *attr, int detachstate);
// detachstate :: [PTHREAD_CREATE_DETACHED, PTHREAD_CREATE_JOINABLE]
/* Both return: 0 if OK, error number on failure */



/* Set stackaddr & stacksize */
#include <pthread.h>
int pthread_attr_getstack(const pthread_attr_t *restrict attr, void **restrict stackaddr, size_t *restrict stacksize);
int pthread_attr_setstack(const pthread_attr_t *attr, void *stackaddr, size_t *stacksize);
/* Both return: 0 if OK, error number on failure */

/* The pthread_attr_setstacksize function is useful
 * when you want to change the default stack size but don't
 * want to deal with allocating the thread stacks on your own */
#include <pthread.h>
int pthread_attr_getstacksize(const pthread_attr_t *restrict attr, size_t *restrict stacksize);
int pthread_attr_setstacksize(pthread_attr_t *attr, size_t stacksize);
/* Both return: 0 if OK, error number on failure */



/* Set guradsize */
/* If the thread's stack pointer overflows into the guard area,
   the application will receive an error, possibly with a signal */
#include <pthread.h>
int pthread_attr_getguardsize(const pthread_attr_t *restrict attr, size_t *restrict guardsize);
int pthread_attr_setguardsize(pthread_attr_t *attr, size_t guardsize);
/* Both return: 0 if OK, error number on failure */



/* Set concurrency level */
#include <pthread.h>
int pthread_getconcurrency(void);
/* Returns: current concurrency level */
int pthread_setconcurrency(int level);
/* Returns: 0 if OK, error number on failure */



/*  cancelability state & cancelability type affect the behavior
    of a thread in response to a call to pthread_cancel */
/* Set cancelability state */
#include <pthread.h>
int pthread_setcancelstate(int state, int *oldstate);
// state :: [PTHREAD_CANCEL_ENABLE, PTHREAD_CANCEL_DISABLE]
/* Returns: 0 if OK, error number on failure */

#include <pthread.h>
void pthread_testcancel(void);




/* Set cancelability type */
/* The default cancellation type we have been describing is known as deferred cancellation.
   We can change the cancellation type by calling pthread_setcanceltype */
#include <pthread.h>
int pthread_setcanceltype(int type, int *oldtype);
// type :: [PTHREAD_CANCEL_DEFERRED, PTHREAD_CANCEL_ASYNCHRONOUS]
/* Returns: 0 if OK, error number on failure */




/* ============== Mutex Attributes ============== */

#include <pthread.h>
int pthread_mutexattr_init(pthread_mutexattr_t *attr);
int pthread_mutexattr_destroy(pthread_mutexattr_t *attr);
/* Both return: 0 if OK, error number on failure */

#include <pthread.h>
int pthread_mutexattr_getpshared(const pthread_mutexattr_t * restrict attr, int *restrict pshared);
int pthread_mutexattr_setpshared(pthread_mutexattr_t *attr, int pshared);
// pshared :: [PTHREAD_PROCESS_PRIVATE, PTHREAD_PROCESS_SHARED]
/* Both return: 0 if OK, error number on failure */

#include <pthread.h>
int pthread_mutexattr_gettype(const pthread_mutexattr_t * restrict attr, int *restrict type);
int pthread_mutexattr_settype(pthread_mutexattr_t *attr, int type);
// type :: [PTHREAD_MUTEX_NORMAL, PTHREAD_MUTEX_ERRORCHECK, PTHREAD_MUTEX_RECURSIVE, PTHREAD_MUTEX_DEFAULT]
/* Both return: 0 if OK, error number on failure */


/* ============== RWLock Attributes ============== */

#include <pthread.h>
int pthread_rwlockattr_init(pthread_rwlockattr_t *attr);
int pthread_rwlockattr_destroy(pthread_rwlockattr_t *attr);
/* Both return: 0 if OK, error number on failure */

#include <pthread.h>
int pthread_rwlockattr_getpshared(const pthread_rwlockattr_t * restrict attr, int *restrict pshared);
int pthread_rwlockattr_setpshared(pthread_rwlockattr_t *attr, int pshared);
/* Both return: 0 if OK, error number on failure */


/* ============== Condition Variables Attributes ============== */

#include <pthread.h>
int pthread_condattr_init(pthread_condattr_t *attr);
int pthread_condattr_destroy(pthread_condattr_t *attr);
/* Both return: 0 if OK, error number on failure */

#include <pthread.h>
int pthread_condattr_getpshared(const pthread_condattr_t * restrict attr, int *restrict pshared);
int pthread_condattr_setpshared(pthread_condattr_t *attr, int pshared);
/* Both return: 0 if OK, error number on failure */




/* ============== Thread-Specific Data ============== */

#include <pthread.h>
int pthread_key_create(pthread_key_t *keyp, void (*destructor)(void *));
/* Returns: 0 if OK, error number on failure */
/* When the thread exits, if the thread-specific data address has been set to a non-null value,
   the destructor function is called with the data address as the only argument */
/* destructor is called when:
   1, calls pthread_exit
   2, exits normally by returning */
/* destructor is not called when:
   1, calls exit, _exit, _Exit
   2, calls abort
   3, exits abnormally */

#include <pthread.h>
void *pthread_getspecific(pthread_key_t key);
/* Returns: thread-specific data value or NULLif no value has been associated with the key */

#include <pthread.h>
int pthread_setspecific(pthread_key_t key, const void *value);
/* Returns: 0 if OK, error number on failure */

#include <pthread.h>
int pthread_key_delete(pthread_key_t *key);
/* Returns: 0 if OK, error number on failure */




/* ============== Pthread Once ============== */
#include <pthread.h>
pthread_once_t initflag = PTHREAD_ONCE_INIT;
int pthread_once(pthread_once_t *initflag, void (*initfn)(void));
/* Returns: 0 if OK, error number on failure */
/* The initflag must be a nonlocal variable (i.e., global or static)
   and initialized to PTHREAD_ONCE_INIT */





/* ============== Signal in Thread ============== */

#include <signal.h>
int pthread_sigmask(int how, const sigset_t *restrict set, sigset_t *restrict oset);
/* Returns: 0 if OK, error number on failure */

#include <signal.h>
int sigwait(const sigset_t *restrict set, int *restrict signop);
/* Returns: 0 if OK, error number on failure */

#include <signal.h>
int pthread_kill(pthread_t thread, int signo);
/* Returns: 0 if OK, error number on failure */




/* ============== Thread and Fork ============== */

int pthread_atfork(void (*prepare)(void), void (*parent)(void), void (*child)(void));
/* Returns: 0 if OK, error number on failure */




/* ============== File Lock ============== */

/* This allows applications to compose multiple calls
   to standard I/O functions into atomic sequences */
#include <stdio.h>
int ftrylockfile(FILE *fp);
/* Returns: 0 if OK, nonzero if lock can't be acquired */
void flockfile(FILE *fp);
void funlockfile(FILE *fp);

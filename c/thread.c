#include <pthread.h>

/*
 * THREAD CONTROL
 */

/*********************** Thread Attributes *************************/

/*
 * POSIX.1 thread attributes:
 * detachstate  detached thread attribute
 * guardsize    guard buffer size in bytes at end of thread stack
 * stackaddr    lowest address of thread stack
 * stacksize    size in bytes of thread stack
 */

/* Both return: 0 if OK, error number on failure */
int pthread_attr_init(pthread_attr_t *attr);
int pthread_attr_destroy(pthread_attr_t *attr);

/* Both return: 0 if OK, error number on failure */
int pthread_attr_getdetachstate(const pthread_attr_t *restrict attr, int *detachstate);
int pthread_attr_setdetachstate(pthread_attr_t *attr, int detachstate); /* detachstate :: [PTHREAD_CREATE_DETACHED, PTHREAD_CREATE_JOINABLE] */

/* Both return: 0 if OK, error number on failure */
int pthread_attr_getstack(const pthread_attr_t *restrict attr, void **restrict stackaddr, size_t *restrict stacksize);
int pthread_attr_setstack(const pthread_attr_t *attr, void *stackaddr, size_t *stacksize);

/* Both return: 0 if OK, error number on failure */
int pthread_attr_getstacksize(const pthread_attr_t *restrict attr, size_t *restrict stacksize);
int pthread_attr_setstacksize(pthread_attr_t *attr, size_t stacksize); /* The pthread_attr_setstacksizefunction is useful
                                                                        * when you want to change the default stack size but don't
                                                                        * want to deal with allocating the thread stacks on your own
                                                                        */

/* Both return: 0 if OK, error number on failure */
int pthread_attr_getguardsize(const pthread_attr_t *restrict attr, size_t *restrict guardsize);
int pthread_attr_setguardsize(pthread_attr_t *attr, size_t guardsize);

/* Returns: current concurrency level */
int pthread_getconcurrency(void);
/* Returns: 0 if OK, error number on failure */
int pthread_setconcurrency(int level);

/*********************** Synchronization Attributes *************************/

/* Both return: 0 if OK, error number on failure */
int pthread_mutexattr_init(pthread_mutexattr_t *attr);
int pthread_mutexattr_destroy(pthread_mutexattr_t *attr);

/* Two attributes of interest for MUTEX are the PROCESS-SHARED attribute and the TYPE attribute */

/* Both return: 0 if OK, error number on failure */
int pthread_mutexattr_getpshared(const pthread_mutexattr_t * restrict attr, int *restrict pshared);
int pthread_mutexattr_setpshared(pthread_mutexattr_t *attr, int pshared); /* pshared :: [PTHREAD_PROCESS_PRIVATE, PTHREAD_PROCESS_SHARED] */

/* Both return: 0 if OK, error number on failure */
int pthread_mutexattr_gettype(const pthread_mutexattr_t * restrict attr, int *restrict type);
int pthread_mutexattr_settype(pthread_mutexattr_t *attr, int type); /* type :: [PTHREAD_MUTEX_NORMAL,
                                                                     *          PTHREAD_MUTEX_ERRORCHECK,
                                                                     *          PTHREAD_MUTEX_RECURSIVE,
                                                                     *          PTHREAD_MUTEX_DEFAULT]
                                                                     */

/* The only attribute supported for reader–writer locks is the process-shared attribute */
/* Both return: 0 if OK, error number on failure */
int pthread_rwlockattr_init(pthread_rwlockattr_t *attr);
int pthread_rwlockattr_destroy(pthread_rwlockattr_t*attr);

int pthread_rwlockattr_getpshared(const pthread_rwlockattr_t * restrict attr, int *restrict pshared);
int pthread_rwlockattr_setpshared(pthread_rwlockattr_t *attr, int pshared);

/* Both return: 0 if OK, error number on failure */
int pthread_condattr_init(pthread_condattr_t *attr);
int pthread_condattr_destroy(pthread_condattr_t *attr);

/* Both return: 0 if OK, error number on failure */
int pthread_condattr_getpshared(const pthread_condattr_t * restrict attr, int *restrict pshared);
int pthread_condattr_setpshared(pthread_condattr_t *attr, int pshared);

/*********************** Synchronization Attributes *************************/

/* Thread-Specific Data */

/* Returns: 0 if OK, error number on failure */
int pthread_key_create(pthread_key_t *keyp, void (*destructor)(void *));

/* Returns: 0 if OK, error number on failure */
int pthread_key_delete(pthread_key_t *key);

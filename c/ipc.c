/* =============== System V Semaphore =============== */
/* The kernel maintains a semid_ds structure for each semaphore set: */
struct semid_ds {
    struct ipc_perm sem_perm;   /* see Section 15.6.2 */
    unsigned short  sem_nsems;  /* number of semaphoresin set */
    time_t          sem_otime;  /* last-semop() time */
    time_t          sem_ctime;  /* last-change time */
};

/* Each semaphore is represented by an anonymous structure: */
struct {
    unsigned short semval;  /* semaphore value, always >= 0 */
    pid_t          sempid;  /* pid for last operation */
    unsigned short semncnt; /* # processes awaiting semval>curval */
    unsigned short semzcnt; /* # processes awaiting semval==0 */
};

#include <sys/sem.h>
int semget(key_t key, int nsems, int flag);
/* Returns: semaphore ID if OK, –1 on error */
/* When a new set is created, the following members of the semid_ds structure are initialized:
   ipc_perm, sem_otime, sem_ctime, sem_nsems */
/* If we are referencing an existing set (as client), we can specify nsems as 0 */

#include <sys/sem.h>
int semctl(int semid, int semnum, int cmd, ... /* union semun arg */);
/* Note that the optional argument is the actual union, not a pointer to the union */
/* For all the GET commands other than GETALL, the function returns the corresponding value
   For the remaining commands, the return value is 0 */
/* If we set the value of a semaphore using semctl, with either the SETVAL or SETALL,
   the 'adjustment value' for that semaphore in all processes is set to 0 */

union semun {
    int             val;     /* for SETVAL */
    struct semid_ds *buf;    /* for IPC_STAT and IPC_SET */
    unsigned short  *array;  /* for GETALL and SETALL */
};

/*
  cmd      | Description
  ---------|---------------------------------------------------------------------------------
  IPC_STAT | Fetch the semid_ds structure for this set, storing it in arg.buf
  IPC_SET  | Set the sem_perm.uid, sem_perm.gid, and sem_perm.mode fields from arg.buf
  IPC_RMID | Remove the semaphore set from the system
  IPC_STAT | Fetch the semid_ds structure for this set, storing it in arg.buf
  GETVAL   | Return the value of semval for the member semnum
  SETVAL   | Set the value of semval for the member semnum. The value is specified by arg.val
  GETPID   | Return the value of sempid for the member semnum
  GETNCNT  | Return the value of semncnt for the member semnum
  GETZCNT  | Return the value of semzcnt for the member semnum
  GETALL   | Fetch all the semaphore values in the set. These values are stored in arg.array
  SETALL   | Set all the semaphore values in the set to arg.array.
*/

/* function semop semopatomically performs an array of operations on a semaphore set */
#include <sys/sem.h>
int semop(int semid, struct sembuf semoparray[], size_t nops);
/* Returns: 0 if OK, -1 on error */

struct sembuf {
    unsigned short sem_num; /* member # in set (0,1, ..., nsems-1) */
    short          sem_op;  /* operation (negative, 0, or positive) */
    short          sem_flg; /* IPC_NOWAIT, SEM_UNDO */
};

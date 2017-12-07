#include "sem.h"

int main(int argc, char** args) {
    int sem;
    if (!strcmp(args[1],"-c"))
        sem = createSem(120, atoi(args[2]));
    if (!strcmp(args[1],"-v"))
        sem = getSem(sem);
    if (!strcmp(args[1],"-r"))
        sem = delSem(sem);
}

int createSem(int key, int N){
    printf("%d,%d\n",key,N);
    int sem = 0;
    printf("%d\n",semget(key, 1, IPC_EXCL));

  if(sem == -1){
    printf("Sorry bro, semaphore already exists.\n");
    return 0;
  }
    semctl(sem,0,SETVAL, N);
    printf("Semaphore hast been made: %d\n", sem);
  return sem;
}

int getSem(int key){
  int sem = semctl(key, 0, GETVAL);
    if(sem == -1){
        printf("What chu doin' man! You gotta make sem semaphore first!\n");
    }
    printf("Ye Semaphore val: %d\n", sem);
  return sem;
}

int delSem(int key){
    int sem = semctl(key, 0, IPC_RMID);
    if(sem == -1){
        printf("Nothin to del, boss!\n");
        return 0;
    }
    printf("Deleted sem: %d\n",sem);
    return sem;
}

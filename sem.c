#include "sem.h"

int main(int argc, char** args) {
    int sem = IPC_PRIVATE;
    if (!strcmp(args[1],"-c"))
        createSem(atoi(args[2]));
    //printf("Sem: %d\n", sem);
    if (!strcmp(args[1],"-v"))
        getSem();
    if (!strcmp(args[1],"-r"))
        delSem();
}

int createSem(int N){
    int sem = semget(10, 1, IPC_EXCL | IPC_CREAT);
    //printf("Hi %s\n",strerror(errno));
  if(sem == -1){
    printf("Sorry bro, semaphore already exists.\n");
    return 0;
  }
    semctl(sem,0,SETVAL, N);
    printf("Semaphore hast been made: %d\n", sem);
  return sem;
}

int getSem(){
  int sem = semget(10, 1, IPC_CREAT);
    semctl(sem, 0, GETVAL);
    if(sem == -1){
        printf("What chu doin' man! You gotta make sem semaphore first!\n");
        return 0;
    }
    printf("Ye Semaphore val: %d\n", sem);
  return sem;
}

int delSem(){
    int sem = semget(10, 1, IPC_CREAT);
    semctl(sem, 0, IPC_RMID);
    if(sem == -1){
        printf("Nothin to del, boss!\n");
        return 0;
    }
    printf("Deleted sem: %d\n",sem);
    return sem;
}

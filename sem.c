#include "sem.h"

int main(char* args) {
  

}

int createSem(char* key, int N){
  int sem = semget(key, N, IPC_EXCL);
  if(sem == -1){
    printf("Sorry bro, sem already exists.\n");
    return 0;
  }
  return sem;
}

int getSem(char* key,int N){
  int sem = semctl(key, 0, getval);
  return sem;
}

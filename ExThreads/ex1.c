/*
* compilar: 
    gcc -o ex1 ex1.c -lpthread
*/ 

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int x; // var global
void *func(void *param) {
    
    pthread_exit(0);
}

int main() {
    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, func, NULL);
    pthread_join(tid, NULL);
    printf("%d", x);
}
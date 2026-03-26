/*
* compilar:
    gcc -o ex1 ex1.c -lpthread
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define CONST 10;

int value = 0;

void *teclado(void *param) {
    printf("Entre com o valor: ");
    scanf("%d", &value);
    pthread_exit(0);
}

void *soma_constante(void *param) {
    value += CONST;
    pthread_exit(0);
}

void *print_tela(void *param) {
    printf("Valor final: %d", value);
    pthread_exit(0);
}

int main() {
    pthread_t tid_1, tid_2, tid_3;
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    pthread_create(&tid_1, &attr, teclado, NULL);
    pthread_create(&tid_2, &attr, soma_constante, NULL);
    pthread_create(&tid_3, &attr, print_tela, NULL);
    
    
    pthread_join(tid_1, NULL);
    pthread_join(tid_2, NULL);
    pthread_join(tid_3, NULL);

    printf("\nRetornou para o processo!");
}
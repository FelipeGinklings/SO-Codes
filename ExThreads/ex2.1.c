/*
 *   Faça uma aplicação que tenha um vetor de 10 valores, gerados randomicamente ou com entrada do usuário.
 *   Com o vetor preenchido, eles devem gerar uma soma e um produto (resultado de uma multiplicação).
 *   Você deve usar pelo menos duas threads para cada operação (soma e multiplicação)
 *   e utilizar os dados no vetor original.
 */

/*
* compilar:
    gcc -o ex2 ex2.c -lpthread
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int vet[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
pthread_mutex_t mutex_sum = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_mul = PTHREAD_MUTEX_INITIALIZER;
int sum = 0;
int mul = 1;
int sum_i = 0;
int mul_i = 0;

void* soma1(void* param) {
    pthread_mutex_lock(&mutex_sum);
    while (sum_i < 10) {
        sum += vet[sum_i];
        sum_i++;
    }
    pthread_mutex_unlock(&mutex_sum);
    pthread_exit(0);
}

void* soma2(void* param) {
    pthread_mutex_lock(&mutex_sum);
    while (sum_i < 10) {
        sum += vet[sum_i];
        sum_i++;
    }
    pthread_mutex_unlock(&mutex_sum);
    pthread_exit(0);
}

void* mul1(void* param) {
    pthread_mutex_lock(&mutex_mul);
    while (sum_i < 10) {
        mul *= vet[sum_i];
        sum_i++;
    }
    pthread_mutex_unlock(&mutex_mul);
    pthread_exit(0);
}

void* mul2(void* param) {
    pthread_mutex_lock(&mutex_mul);
    while (sum_i < 10) {
        mul *= vet[sum_i];
        sum_i++;
    }
    pthread_mutex_unlock(&mutex_mul);
    pthread_exit(0);
}

int main() {
    // preenche_vetor();
    pthread_t tid_soma_1, tid_mul_1, tid_soma_2, tid_mul_2;
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    pthread_create(&tid_soma_1, &attr, soma1, NULL);
    pthread_create(&tid_soma_2, &attr, soma2, NULL);
    pthread_create(&tid_mul_1, &attr, mul1, NULL);
    pthread_create(&tid_mul_2, &attr, mul2, NULL);

    pthread_join(tid_soma_1, NULL);
    pthread_join(tid_soma_2, NULL);
    pthread_join(tid_mul_1, NULL);
    pthread_join(tid_mul_2, NULL);

    printf("Retornou para o processo!");
}
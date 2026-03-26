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
int sum_1 = 0;
int sum_2 = 0;
int mul_1 = 1;
int mul_2 = 1;

void preenche_vetor() {
    srand(time(NULL));
    for (size_t i = 0; i < 10; i++) {
        int random_num = rand() % 10 + 1;
        printf("%d\t", random_num);
        vet[i] = random_num;
    }
}

void* soma1(void* param) {
    for (size_t i = 0; i < 10 / 2; i++) sum_1 += vet[i];
    pthread_exit(0);
}
void* soma2(void* param) {
    for (size_t i = 10 / 2; i < 10; i++) sum_2 += vet[i];
    pthread_exit(0);
}

void* mul1(void* param) {
    for (size_t i = 0; i < 10 / 2; i++) mul_1 *= vet[i];
    pthread_exit(0);
}
void* mul2(void* param) {
    for (size_t i = 10 / 2; i < 10; i++) mul_2 *= vet[i];
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

    printf("\nResultado da soma: %d\n", sum_1);
    printf("\nResultado da soma: %d\n", sum_2);
    printf("\nResultado da multiplicação: %d\n", mul_1);
    printf("\nResultado da multiplicação: %d\n", mul_2);

    printf("Retornou para o processo!");
}
#include <stdio.h>
#include <stdlib.h>
#define GENERIC_CIRCULAR_QUEUE_IMPLEMENTATION
#define BIQUEUE_IMPLEMENTATION
#include "../include/generic_circular_queue.h"
#include "../include/generic_biqueue.h"

void print_int(int value) {
    printf("%d ", value);
}

int main(void) {
    printf("=== Prueba de Cola Circular Genérica (int) ===\n");
    CQueue_int* cqueue = CQueue_int_create();

    CQueue_int_enqueue(cqueue, 10);
    CQueue_int_enqueue(cqueue, 20);
    CQueue_int_enqueue(cqueue, 30);

    printf("Elementos en la cola circular: ");
    CQueue_int_print(cqueue, print_int);
    printf("\n");

    int valor;
    CQueue_int_dequeue(cqueue, &valor);
    printf("Elemento desencolado: %d\n", valor);

    printf("Elementos restantes: ");
    CQueue_int_print(cqueue, print_int);
    printf("\n");

    CQueue_int_destroy(cqueue);

    printf("\n=== Prueba de Bicola Genérica (int) ===\n");
    Biqueue_int* biqueue = Biqueue_int_create();

    Biqueue_int_enqueue_back(biqueue, 1);
    Biqueue_int_enqueue_front(biqueue, 2);
    Biqueue_int_enqueue_back(biqueue, 3);

    printf("Elementos en la bicola: ");
    Biqueue_int_print(biqueue, print_int);

    printf("Desencolando por el frente: ");
    while (!Biqueue_int_is_empty(biqueue)) {
        int v;
        Biqueue_int_dequeue_front(biqueue, &v);
        printf("%d ", v);
    }
    printf("\n");

    Biqueue_int_enqueue_front(biqueue, 4);
    Biqueue_int_enqueue_back(biqueue, 5);

    printf("Elementos en la bicola: ");
    Biqueue_int_print(biqueue, print_int);

    printf("Desencolando por el final: ");
    while (!Biqueue_int_is_empty(biqueue)) {
        int v;
        Biqueue_int_dequeue_back(biqueue, &v);
        printf("%d ", v);
    }
    printf("\n");

    Biqueue_int_destroy(biqueue);

    return 0;
}
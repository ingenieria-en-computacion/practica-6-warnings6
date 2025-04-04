#include <stdio.h>
#include "generic_biqueue.h"
#include "generic_circular_queue.h"
int main() {
    // Prueba de la Bicola Genérica
    printf("Prueba de la Bicola Genérica:\n");
    Biqueue_int* biqueue = Biqueue_int_create();
    if (!biqueue) {
        printf("Error al crear la bicola.\n");
        return 1;
    }

    // Encolar al frente y al final
    Biqueue_int_enqueue_front(biqueue, 10);
    Biqueue_int_enqueue_back(biqueue, 20);
    Biqueue_int_enqueue_front(biqueue, 5);
    Biqueue_int_enqueue_back(biqueue, 30);

    // Mostrar los elementos de la bicola
    int value;
    while (!Biqueue_int_is_empty(biqueue)) {
        Biqueue_int_dequeue_front(biqueue, &value);
        printf("Elemento desencolado del frente: %d\n", value);
    }

    Biqueue_int_destroy(biqueue);

    // Prueba de la Cola Circular Genérica
    printf("\nPrueba de la Cola Circular Genérica:\n");
    CQueue_int* cqueue = CQueue_int_create();
    if (!cqueue) {
        printf("Error al crear la cola circular.\n");
        return 1;
    }

    // Encolar elementos
    CQueue_int_enqueue(cqueue, 10);
    CQueue_int_enqueue(cqueue, 20);
    CQueue_int_enqueue(cqueue, 30);
    CQueue_int_enqueue(cqueue, 40);
    CQueue_int_enqueue(cqueue, 50);

    // Intentar encolar en una cola llena
    if (!CQueue_int_enqueue(cqueue, 60)) {
        printf("La cola circular está llena.\n");
    }

    // Desencolar elementos
    while (!CQueue_int_is_empty(cqueue)) {
        CQueue_int_dequeue(cqueue, &value);
        printf("Elemento desencolado: %d\n", value);
    }

    // Intentar desencolar de una cola vacía
    if (!CQueue_int_dequeue(cqueue, &value)) {
        printf("La cola circular está vacía.\n");
    }

    CQueue_int_destroy(cqueue);

    return 0;
}
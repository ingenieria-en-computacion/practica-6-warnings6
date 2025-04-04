#include <stdio.h>
#include <stdlib.h>
#define GENERIC_CIRCULAR_QUEUE_IMPLEMENTATION
#define BIQUEUE_IMPLEMENTATION
#include "generic_circular_queue.h"
#include "generic_biqueue.h"

// Función auxiliar para imprimir enteros
void print_int(int value) {
    printf("%d ", value);
}

// Pruebas para la cola circular
void test_circular_queue() {
    printf("=== Pruebas para la Cola Circular ===\n");

    // Crear una cola circular de enteros
    CQueue_int* cqueue = CQueue_int_create();
    if (!cqueue) {
        fprintf(stderr, "Error al crear la cola circular.\n");
        exit(EXIT_FAILURE);
    }

    // Insertar elementos en la cola
    CQueue_int_enqueue(cqueue, 10);
    CQueue_int_enqueue(cqueue, 20);
    CQueue_int_enqueue(cqueue, 30);

    // Imprimir los elementos de la cola
    printf("Elementos en la cola: ");
    CQueue_int_print(cqueue, print_int);
    printf("\n");

    // Eliminar elementos de la cola
    int value;
    printf("Eliminando elementos: ");
    while (!CQueue_int_is_empty(cqueue)) {
        CQueue_int_dequeue(cqueue, &value);
        printf("%d ", value);
    }
    printf("\n");

    // Prueba de eliminación en una cola vacía
    printf("Intentando eliminar de una cola vacía: ");
    if (!CQueue_int_dequeue(cqueue, &value)) {
        printf("Operación fallida (cola vacía).\n");
    }

    // Destruir la cola
    CQueue_int_destroy(cqueue);
}

// Pruebas para la bicola
void test_biqueue() {
    printf("=== Pruebas para la Bicola ===\n");

    // Crear una bicola de enteros
    Biqueue_int* biqueue = Biqueue_int_create();
    if (!biqueue) {
        fprintf(stderr, "Error al crear la bicola.\n");
        exit(EXIT_FAILURE);
    }

    // Insertar elementos en la bicola
    Biqueue_int_enqueue_front(biqueue, 10);
    Biqueue_int_enqueue_back(biqueue, 20);
    Biqueue_int_enqueue_front(biqueue, 5);

    // Imprimir los elementos de la bicola
    printf("Elementos en la bicola (de frente a atrás): ");
    int value;
    while (!Biqueue_int_is_empty(biqueue)) {
        Biqueue_int_dequeue_front(biqueue, &value);
        printf("%d ", value);
    }
    printf("\n");

    // Insertar y eliminar desde ambos extremos
    Biqueue_int_enqueue_back(biqueue, 30);
    Biqueue_int_enqueue_front(biqueue, 40);
    printf("Elementos en la bicola después de nuevas inserciones: ");
    while (!Biqueue_int_is_empty(biqueue)) {
        Biqueue_int_dequeue_back(biqueue, &value);
        printf("%d ", value);
    }
    printf("\n");

    // Prueba de eliminación en una bicola vacía
    printf("Intentando eliminar de una bicola vacía: ");
    if (!Biqueue_int_dequeue_front(biqueue, &value)) {
        printf("Operación fallida (bicola vacía).\n");
    }

    // Destruir la bicola
    Biqueue_int_destroy(biqueue);
}

// Pruebas adicionales para la cola circular
void test_circular_queue_edge_cases() {
    printf("=== Pruebas de Casos Límite para la Cola Circular ===\n");

    // Crear una cola circular de enteros
    CQueue_int* cqueue = CQueue_int_create();
    if (!cqueue) {
        fprintf(stderr, "Error al crear la cola circular.\n");
        exit(EXIT_FAILURE);
    }

    // Insertar y eliminar repetidamente
    for (int i = 0; i < 5; i++) {
        CQueue_int_enqueue(cqueue, i);
    }
    printf("Elementos en la cola después de inserciones: ");
    CQueue_int_print(cqueue, print_int);
    printf("\n");

    for (int i = 0; i < 5; i++) {
        int value;
        CQueue_int_dequeue(cqueue, &value);
        printf("Eliminado: %d\n", value);
    }

    // Verificar que la cola esté vacía
    if (CQueue_int_is_empty(cqueue)) {
        printf("La cola está vacía después de eliminar todos los elementos.\n");
    }

    // Destruir la cola
    CQueue_int_destroy(cqueue);
}

// Pruebas adicionales para la bicola
void test_biqueue_edge_cases() {
    printf("=== Pruebas de Casos Límite para la Bicola ===\n");

    // Crear una bicola de enteros
    Biqueue_int* biqueue = Biqueue_int_create();
    if (!biqueue) {
        fprintf(stderr, "Error al crear la bicola.\n");
        exit(EXIT_FAILURE);
    }

    // Insertar y eliminar repetidamente desde ambos extremos
    for (int i = 0; i < 5; i++) {
        Biqueue_int_enqueue_front(biqueue, i);
        Biqueue_int_enqueue_back(biqueue, i + 10);
    }

    printf("Elementos en la bicola después de inserciones: ");
    int value;
    while (!Biqueue_int_is_empty(biqueue)) {
        Biqueue_int_dequeue_front(biqueue, &value);
        printf("%d ", value);
    }
    printf("\n");

    // Verificar que la bicola esté vacía
    if (Biqueue_int_is_empty(biqueue)) {
        printf("La bicola está vacía después de eliminar todos los elementos.\n");
    }

    // Destruir la bicola
    Biqueue_int_destroy(biqueue);
}

int main(void) {
    // Ejecutar pruebas para la cola circular
    test_circular_queue();

    // Ejecutar pruebas para la bicola
    test_biqueue();

    // Ejecutar pruebas de casos límite para la cola circular
    test_circular_queue_edge_cases();

    // Ejecutar pruebas de casos límite para la bicola
    test_biqueue_edge_cases();

    return EXIT_SUCCESS;
}
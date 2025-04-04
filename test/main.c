#include <stdio.h>
#include "circularqueue.h"
#include "biqueue.h"

void test_circular_queue() {
    printf("=== Pruebas para la Cola Circular ===\n");

    CQueue *cqueue = cqueue_create();
    if (!cqueue) {
        printf("Error al crear la cola circular.\n");
        return;
    }

    cqueue_enqueue(cqueue, 'A');
    cqueue_enqueue(cqueue, 'B');
    cqueue_enqueue(cqueue, 'C');
    printf("Después de insertar A, B, C: ");
    cqueue_print(cqueue);

    cqueue_dequeue(cqueue);
    printf("Después de eliminar un elemento: ");
    cqueue_print(cqueue);

    printf("Primer elemento: %c\n", cqueue_first(cqueue));
    printf("Último elemento: %c\n", cqueue_last(cqueue));

    cqueue_empty(cqueue);
    printf("Después de vaciar la cola: ");
    cqueue_print(cqueue);

    cqueue_destroy(cqueue);
    printf("Cola circular destruida.\n");
}

void test_biqueue() {
    printf("\n=== Pruebas para la Bicola ===\n");

    BQueue *biqueue = biqueue_create();
    if (!biqueue) {
        printf("Error al crear la bicola.\n");
        return;
    }

    biqueue_enqueue_front(biqueue, 'X');
    biqueue_enqueue_back(biqueue, 'Y');
    biqueue_enqueue_front(biqueue, 'Z');
    printf("Después de insertar Z al frente, Y al final, X al frente: ");
    biqueue_print(biqueue);

    biqueue_dequeue_front(biqueue);
    printf("Después de eliminar un elemento del frente: ");
    biqueue_print(biqueue);

    biqueue_dequeue_back(biqueue);
    printf("Después de eliminar un elemento del final: ");
    biqueue_print(biqueue);

    printf("Primer elemento: %c\n", biqueue_first(biqueue));
    printf("Último elemento: %c\n", biqueue_last(biqueue));

    // Vaciar la bicola
    biqueue_destroy(biqueue);
    printf("Bicola destruida.\n");
}

int main() {
    test_circular_queue();
    test_biqueue();
    return 0;
}
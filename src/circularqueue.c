#include "../include/circularqueue.h"
#include <stdio.h>
#include <stdlib.h>

CQueue *cqueue_create() {
    CQueue *newQueue = (CQueue *)malloc(sizeof(CQueue));
    if (!newQueue) {
        return NULL;
    }
    newQueue->front = -1;
    newQueue->last = -1;
    newQueue->len = 0;
    return newQueue;
}

void cqueue_destroy(CQueue *q) {
    free(q);
}

void cqueue_enqueue(CQueue *q, char d) {
    if (cqueue_is_full(q)) {
        printf("Error: La cola está llena.\n");
        return;
    }
    if (q->front == -1) {
        // Primera inserción
        q->front = q->last = 0;
    } else {
        q->last = (q->last + 1) % MAX_SIZE;
    }
    q->data[q->last] = d;
    q->len++;
}

void cqueue_dequeue(CQueue *q) {
    if (cqueue_is_empty(q)) {
        printf("Error: La cola está vacía.\n");
        return;
    }
    if (q->front == q->last) {
        q->front = q->last = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
    }
    q->len--;
}

char cqueue_first(CQueue *q) {
    if (cqueue_is_empty(q)) {
        printf("Error: La cola está vacía.\n");
        return '\0';
    }
    return q->data[q->front];
}

char cqueue_last(CQueue *q) {
    if (cqueue_is_empty(q)) {
        printf("Error: La cola está vacía.\n");
        return '\0';
    }
    return q->data[q->last];
}

bool cqueue_is_empty(CQueue *q) {
    return q->len == 0;
}

bool cqueue_is_full(CQueue *q) {
    return q->len == MAX_SIZE;
}

void cqueue_empty(CQueue *q) {
    q->front = -1;
    q->last = -1;
    q->len = 0;
}

void cqueue_print(CQueue *q) {
    if (cqueue_is_empty(q)) {
        printf("La cola está vacía.\n");
        return;
    }
    int i = q->front;
    printf("Cola circular: ");
    for (int count = 0; count < q->len; count++) {
        printf("%c ", q->data[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}
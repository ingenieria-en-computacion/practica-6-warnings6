#ifndef __BIQUEUE_H__
#define __BIQUEUE_H__

#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int front;
    int last;
    int len;
} BQueue;

// Declaración de funciones
BQueue *biqueue_create();
void biqueue_destroy(BQueue *biqueue);
bool biqueue_is_empty(BQueue *biqueue);
bool biqueue_is_full(BQueue *biqueue);
void biqueue_enqueue_front(BQueue *biqueue, char d);
void biqueue_enqueue_back(BQueue *biqueue, char d);
void biqueue_dequeue_front(BQueue *biqueue);
void biqueue_dequeue_back(BQueue *biqueue);
char biqueue_first(BQueue *biqueue);
char biqueue_last(BQueue *biqueue);
void biqueue_print(BQueue *biqueue);

#endif
#ifndef __CIRCULARQUEUE_H__
#define __CIRCULARQUEUE_H__
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int front;
    int last;
    int len;
} CQueue;

CQueue *cqueue_create();
void cqueue_destroy(CQueue *q);
void cqueue_enqueue(CQueue *q, char d);
void cqueue_dequeue(CQueue *q);
char cqueue_first(CQueue *q);
char cqueue_last(CQueue *q);
bool cqueue_is_empty(CQueue *q);
bool cqueue_is_full(CQueue *q);
void cqueue_empty(CQueue *q);
void cqueue_print(CQueue *q);

#endif
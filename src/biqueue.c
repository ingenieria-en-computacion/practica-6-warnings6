#include "biqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

BQueue *biqueue_create() {
    BQueue *biqueue = (BQueue *)malloc(sizeof(BQueue));
    if (!biqueue) {
        return NULL;
    }
    biqueue->front = -1;
    biqueue->back = -1;
    biqueue->len = 0;
    return biqueue;
}

void biqueue_destroy(BQueue *biqueue) {
    free(biqueue);
}

bool biqueue_is_empty(BQueue *biqueue) {
    return biqueue->len == 0;
}

bool biqueue_is_full(BQueue *biqueue) {
    return biqueue->len == MAX_SIZE;
}

void biqueue_enqueue_front(BQueue *biqueue, char d) {
    if (biqueue_is_full(biqueue)) {
        printf("Error: La bicola está llena.\n");
        return;
    }
    if (biqueue->front == -1) {
        biqueue->front = biqueue->back = 0;
    } else {
        biqueue->front = (biqueue->front - 1 + MAX_SIZE) % MAX_SIZE;
    }
    biqueue->data[biqueue->front] = d;
    biqueue->len++;
}

void biqueue_enqueue_back(BQueue *biqueue, char d) {
    if (biqueue_is_full(biqueue)) {
        printf("Error: La bicola está llena.\n");
        return;
    }
    if (biqueue->back == -1) {
        biqueue->front = biqueue->back = 0;
    } else {
        biqueue->back = (biqueue->back + 1) % MAX_SIZE;
    }
    biqueue->data[biqueue->back] = d;
    biqueue->len++;
}

void biqueue_dequeue_front(BQueue *biqueue) {
    if (biqueue_is_empty(biqueue)) {
        printf("Error: La bicola está vacía.\n");
        return;
    }
    if (biqueue->front == biqueue->back) {
        biqueue->front = biqueue->back = -1;
    } else {
        biqueue->front = (biqueue->front + 1) % MAX_SIZE;
    }
    biqueue->len--; 
}

void biqueue_dequeue_back(BQueue *biqueue) {
    if (biqueue_is_empty(biqueue)) {
        printf("Error: La bicola está vacía.\n");
        return;
    }
    if (biqueue->front == biqueue->back) {
        biqueue->front = biqueue->back = -1;
    } else {
        biqueue->back = (biqueue->back - 1 + MAX_SIZE) % MAX_SIZE;
    }
    biqueue->len--; 
}

char biqueue_first(BQueue *biqueue) {
    if (biqueue_is_empty(biqueue)) {
        printf("Error: La bicola está vacía.\n");
        return '\0';
    }
    return biqueue->data[biqueue->front];
}

char biqueue_last(BQueue *biqueue) {
    if (biqueue_is_empty(biqueue)) {
        printf("Error: La bicola está vacía.\n");
        return '\0';
    }
    return biqueue->data[biqueue->back];
}

void biqueue_print(BQueue *biqueue) {
    if (biqueue_is_empty(biqueue)) {
        printf("La bicola está vacía.\n");
        return;
    }
    int i = biqueue->front;
    printf("Bicola: ");
    for (int count = 0; count < biqueue->len; count++) {
        printf("%c ", biqueue->data[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}
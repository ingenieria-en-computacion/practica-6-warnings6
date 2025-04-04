#include "nodo.h"

Nodo *node_create(char d){
    Nodo *nodeNew = (Nodo*)malloc(sizeof(Nodo));
    nodeNew->data = d;
    nodeNew->next = NULL;
    return nodeNew;
}

void node_destroy(Nodo *n){
    if(n->next == NULL){
        free(n);
        n = NULL;
    }
}

void node_print(Nodo *n){
    printf("Dato:%c\tSiguiente:%p\n", n->data, n->next);
}
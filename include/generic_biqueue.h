#pragma once
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// ----------------------------
// Macro para declarar estructuras y prototipos de bicola
// ----------------------------
#define DECLARE_GENERIC_BIQUEUE(TYPE) \
    typedef struct Node_##TYPE { \
        TYPE data; \
        struct Node_##TYPE* next; \
        struct Node_##TYPE* prev; \
    } Node_##TYPE; \
    \
    typedef struct { \
        Node_##TYPE* head; \
        Node_##TYPE* tail; \
        size_t length; \
    } Biqueue_##TYPE; \
    \
    Biqueue_##TYPE* Biqueue_##TYPE##_create(void); \
    void Biqueue_##TYPE##_destroy(Biqueue_##TYPE* queue); \
    bool Biqueue_##TYPE##_enqueue_front(Biqueue_##TYPE* queue, TYPE data); \
    bool Biqueue_##TYPE##_enqueue_back(Biqueue_##TYPE* queue, TYPE data); \
    bool Biqueue_##TYPE##_dequeue_front(Biqueue_##TYPE* queue, TYPE* out); \
    bool Biqueue_##TYPE##_dequeue_back(Biqueue_##TYPE* queue, TYPE* out); \
    bool Biqueue_##TYPE##_is_empty(const Biqueue_##TYPE* queue); \
    size_t Biqueue_##TYPE##_length(const Biqueue_##TYPE* queue);

// ----------------------------
// Macro para implementación
// ----------------------------
#define IMPLEMENT_GENERIC_BIQUEUE(TYPE) \
    Biqueue_##TYPE* Biqueue_##TYPE##_create(void) { \
        Biqueue_##TYPE* queue = (Biqueue_##TYPE*)malloc(sizeof(Biqueue_##TYPE)); \
        if (!queue) return NULL; \
        queue->head = queue->tail = NULL; \
        queue->length = 0; \
        return queue; \
    } \
    \
    void Biqueue_##TYPE##_destroy(Biqueue_##TYPE* queue) { \
        if (!queue) return; \
        Node_##TYPE* current = queue->head; \
        while (current) { \
            Node_##TYPE* temp = current; \
            current = current->next; \
            free(temp); \
        } \
        free(queue); \
    } \
    \
    bool Biqueue_##TYPE##_enqueue_front(Biqueue_##TYPE* queue, TYPE data) { \
        if (!queue) return false; \
        Node_##TYPE* new_node = (Node_##TYPE*)malloc(sizeof(Node_##TYPE)); \
        if (!new_node) return false; \
        new_node->data = data; \
        new_node->next = queue->head; \
        new_node->prev = NULL; \
        if (queue->head) queue->head->prev = new_node; \
        queue->head = new_node; \
        if (!queue->tail) queue->tail = new_node; \
        queue->length++; \
        return true; \
    } \
    \
    bool Biqueue_##TYPE##_enqueue_back(Biqueue_##TYPE* queue, TYPE data) { \
        if (!queue) return false; \
        Node_##TYPE* new_node = (Node_##TYPE*)malloc(sizeof(Node_##TYPE)); \
        if (!new_node) return false; \
        new_node->data = data; \
        new_node->prev = queue->tail; \
        new_node->next = NULL; \
        if (queue->tail) queue->tail->next = new_node; \
        queue->tail = new_node; \
        if (!queue->head) queue->head = new_node; \
        queue->length++; \
        return true; \
    } \
    \
    bool Biqueue_##TYPE##_dequeue_front(Biqueue_##TYPE* queue, TYPE* out) { \
        if (!queue || !queue->head) return false; \
        Node_##TYPE* to_delete = queue->head; \
        *out = to_delete->data; \
        queue->head = queue->head->next; \
        if (queue->head) queue->head->prev = NULL; \
        else queue->tail = NULL; \
        free(to_delete); \
        queue->length--; \
        return true; \
    } \
    \
    bool Biqueue_##TYPE##_dequeue_back(Biqueue_##TYPE* queue, TYPE* out) { \
        if (!queue || !queue->tail) return false; \
        Node_##TYPE* to_delete = queue->tail; \
        *out = to_delete->data; \
        queue->tail = queue->tail->prev; \
        if (queue->tail) queue->tail->next = NULL; \
        else queue->head = NULL; \
        free(to_delete); \
        queue->length--; \
        return true; \
    } \
    \
    bool Biqueue_##TYPE##_is_empty(const Biqueue_##TYPE* queue) { \
        return queue->length == 0; \
    } \
    \
    size_t Biqueue_##TYPE##_length(const Biqueue_##TYPE* queue) { \
        return queue->length; \
    }
// Declaración para tipos concretos
DECLARE_GENERIC_BIQUEUE(int)
DECLARE_GENERIC_BIQUEUE(float)

// Implementación para tipos concretos
#define BIQUEUE_IMPLEMENTATION
#ifdef BIQUEUE_IMPLEMENTATION
IMPLEMENT_GENERIC_BIQUEUE(int)
IMPLEMENT_GENERIC_BIQUEUE(float)
#endif

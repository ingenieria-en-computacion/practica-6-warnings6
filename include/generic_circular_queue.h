#pragma once
#include <stdlib.h>
#include <stdbool.h>

// ----------------------------
// Macro para declarar estructuras y prototipos
// ----------------------------
#define DECLARE_GENERIC_CIRCULAR_QUEUE(TYPE) \
    typedef struct CNode_##TYPE { \
        TYPE data; \
        struct CNode_##TYPE* next; \
        struct CNode_##TYPE* prev; \
    } CNode_##TYPE; \
    \
    typedef struct CQueue_##TYPE { \
        CNode_##TYPE* head; \
        CNode_##TYPE* tail; \
        size_t length; \
    } CQueue_##TYPE; \
    \
    CQueue_##TYPE* CQueue_##TYPE##_create(void); \
    void CQueue_##TYPE##_destroy(CQueue_##TYPE* queue); \
    bool CQueue_##TYPE##_enqueue(CQueue_##TYPE* queue, TYPE data); \
    bool CQueue_##TYPE##_dequeue(CQueue_##TYPE* queue, TYPE* out); \
    bool CQueue_##TYPE##_is_empty(const CQueue_##TYPE* queue); \
    size_t CQueue_##TYPE##_length(const CQueue_##TYPE* queue); \
    void CQueue_##TYPE##_print(const CQueue_##TYPE* queue, void (*print_fn)(TYPE)); \
    void CQueue_##TYPE##_clear(CQueue_##TYPE* queue);

// ----------------------------
// Macro para implementar funciones
// ----------------------------
#define IMPLEMENT_GENERIC_CIRCULAR_QUEUE(TYPE) \
    CNode_##TYPE* cnode_##TYPE##__create(TYPE data) { \
        CNode_##TYPE* new_node = malloc(sizeof(CNode_##TYPE)); \
        new_node->data = data; \
        new_node->next = new_node->prev = NULL; \
        return new_node; \
    } \
    \
    CQueue_##TYPE* CQueue_##TYPE##_create(void) { \
        CQueue_##TYPE* queue = malloc(sizeof(CQueue_##TYPE)); \
        if (!queue) return NULL; \
        queue->head = queue->tail = NULL; \
        queue->length = 0; \
        return queue; \
    } \
    \
    void CQueue_##TYPE##_destroy(CQueue_##TYPE* queue) { \
        if (!queue) return; \
        CNode_##TYPE* current = queue->head; \
        while (current) { \
            CNode_##TYPE* temp = current; \
            current = current->next; \
            free(temp); \
            if (current == queue->head) break; \
        } \
        free(queue); \
    } \
    \
    bool CQueue_##TYPE##_enqueue(CQueue_##TYPE* queue, TYPE data) { \
        if (!queue) return false; \
        CNode_##TYPE* new_node = cnode_##TYPE##__create(data); \
        if (!new_node) return false; \
        if (!queue->head) { \
            queue->head = queue->tail = new_node; \
            new_node->next = new_node->prev = new_node; \
        } else { \
            new_node->next = queue->head; \
            new_node->prev = queue->tail; \
            queue->tail->next = new_node; \
            queue->head->prev = new_node; \
            queue->tail = new_node; \
        } \
        queue->length++; \
        return true; \
    } \
    \
    bool CQueue_##TYPE##_dequeue(CQueue_##TYPE* queue, TYPE* out) { \
        if (!queue || queue->length == 0) return false; \
        CNode_##TYPE* to_delete = queue->head; \
        if (out) *out = to_delete->data; \
        if (queue->head == queue->tail) { \
            queue->head = queue->tail = NULL; \
        } else { \
            queue->head = queue->head->next; \
            queue->head->prev = queue->tail; \
            queue->tail->next = queue->head; \
        } \
        free(to_delete); \
        queue->length--; \
        return true; \
    } \
    \
    bool CQueue_##TYPE##_is_empty(const CQueue_##TYPE* queue) { \
        return queue->length == 0; \
    } \
    \
    size_t CQueue_##TYPE##_length(const CQueue_##TYPE* queue) { \
        return queue->length; \
    } \
    \
    void CQueue_##TYPE##_print(const CQueue_##TYPE* queue, void (*print_fn)(TYPE)) { \
        if (!queue || queue->length == 0) return; \
        CNode_##TYPE* current = queue->head; \
        do { \
            print_fn(current->data); \
            current = current->next; \
        } while (current != queue->head); \
    } \
    \
    void CQueue_##TYPE##_clear(CQueue_##TYPE* queue) { \
        if (!queue) return; \
        while (!CQueue_##TYPE##_is_empty(queue)) { \
            TYPE temp; \
            CQueue_##TYPE##_dequeue(queue, &temp); \
        } \
    }

// ----------------------------
// Declaración para tipos concretos
// ----------------------------
DECLARE_GENERIC_CIRCULAR_QUEUE(int)
DECLARE_GENERIC_CIRCULAR_QUEUE(char)
DECLARE_GENERIC_CIRCULAR_QUEUE(float)

// ----------------------------
// Implementación para tipos concretos
// ----------------------------
#ifdef GENERIC_CIRCULAR_QUEUE_IMPLEMENTATION
IMPLEMENT_GENERIC_CIRCULAR_QUEUE(int)
IMPLEMENT_GENERIC_CIRCULAR_QUEUE(char)
IMPLEMENT_GENERIC_CIRCULAR_QUEUE(float)
#endif
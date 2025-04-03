#pragma once
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// ----------------------------
// Macro para declarar estructuras y prototipos
// ----------------------------
#define DECLARE_LINKED_LIST(TYPE) \
    typedef struct Node_##TYPE { \
        TYPE data; \
        struct Node_##TYPE* next; \
        struct Node_##TYPE* prev;  \
    } Node_##TYPE; \
    Node_##TYPE* node_##TYPE##__create(TYPE);\
    Node_##TYPE* node_##TYPE##_destroy(Node_##TYPE*);\
    \
    typedef struct { \
        Node_##TYPE* head; \
        Node_##TYPE* tail; \
        size_t length; \
    } List_##TYPE; \
    \
    List_##TYPE* list_##TYPE##_create(void); \
    void list_##TYPE##_destroy(List_##TYPE* list); \
    bool list_##TYPE##_insert(List_##TYPE* list, TYPE data, size_t pos); \
    bool list_##TYPE##_append(List_##TYPE* list, TYPE data); \
    bool list_##TYPE##_prepend(List_##TYPE* list, TYPE data);  \
    bool list_##TYPE##_remove_at(List_##TYPE* list, size_t pos); \
    bool list_##TYPE##_remove_front(List_##TYPE* list); \
    bool list_##TYPE##_remove_back(List_##TYPE* list);  \
    bool list_##TYPE##_get(const List_##TYPE* list, size_t pos, TYPE* out); \
    size_t list_##TYPE##_length(const List_##TYPE* list); \
    void list_##TYPE##_print(const List_##TYPE* list, void (*print_fn)(TYPE));\
    bool list_##TYPE##_is_empty(const List_##TYPE* list); \
    void list_##TYPE##_clear(List_##TYPE* list);

// ----------------------------
// Macro para implementación
// ----------------------------
#define IMPLEMENT_LINKED_LIST(TYPE) \
    Node_##TYPE* node_##TYPE##__create(TYPE data){\
        Node_##TYPE* new_node = malloc(sizeof(Node_##TYPE)); \
        new_node->data = data;\
        new_node->next = new_node->prev = NULL; \
        return new_node;\
    }\
    \
    List_##TYPE* list_##TYPE##_create(void) { \
        List_##TYPE* list = malloc(sizeof(List_##TYPE)); \
        if (!list) return NULL; \
        list->head = list->tail = NULL; \
        list->length = 0; \
        return list; \
    } \
    \
    void list_##TYPE##_destroy(List_##TYPE* list) { \
        if (!list) return; \
        Node_##TYPE* current = list->head; \
        while (current) { \
            Node_##TYPE* temp = current; \
            current = current->next; \
            free(temp); \
        } \
        free(list); \
    } \
    \
    bool list_##TYPE##_append(List_##TYPE* list, TYPE data) { \
        if (!list) return false; \
        Node_##TYPE* new_node = node_##TYPE##__create(data); \
        if (!new_node) return false; \
        if (!list->tail) { \
            list->head = list->tail = new_node; \
        } else { \
            list->tail->next = new_node; \
            new_node->prev = list->tail;  \
            list->tail = new_node; \
        } \
        new_node->next = list->head;  \
        list->head->prev = new_node;  \
        list->length++; \
        return true; \
    } \
    \
    bool list_##TYPE##_prepend(List_##TYPE* list, TYPE data) { \
        if (!list) return false; \
        Node_##TYPE* new_node = node_##TYPE##__create(data); \
        if (!new_node) return false; \
        if (!list->head) { \
            list->head = list->tail = new_node; \
        } else { \
            new_node->next = list->head; \
            list->head->prev = new_node; \
            list->head = new_node; \
        } \
        new_node->prev = list->tail;  \
        list->tail->next = new_node;  \
        list->length++; \
        return true; \
    } \
    \
    bool list_##TYPE##_remove_front(List_##TYPE* list) { \
        if (!list || !list->head) return false; \
        Node_##TYPE* to_delete = list->head; \
        list->head = list->head->next; \
        if (list->head) list->head->prev = list->tail;  \
        else list->tail = NULL; \
        free(to_delete); \
        list->length--; \
        return true; \
    } \
    \
    bool list_##TYPE##_remove_back(List_##TYPE* list) { \
        if (!list || !list->tail) return false; \
        Node_##TYPE* to_delete = list->tail; \
        list->tail = list->tail->prev; \
        if (list->tail) list->tail->next = list->head;  \
        else list->head = NULL; \
        free(to_delete); \
        list->length--; \
        return true; \
    }

// ----------------------------
// Declaración para tipos concretos
// ----------------------------
DECLARE_LINKED_LIST(int)
DECLARE_LINKED_LIST(char)
DECLARE_LINKED_LIST(float)

// ----------------------------
// Implementación para tipos concretos
// ----------------------------
#ifdef LINKED_LIST_IMPLEMENTATION
IMPLEMENT_LINKED_LIST(int)
IMPLEMENT_LINKED_LIST(char)
IMPLEMENT_LINKED_LIST(float)
#endif


#include "../include/list.h"

#include <stdio.h>
#include <stdlib.h>

/* Internal structs */
typedef struct ListNode {
    int value;
    struct ListNode *next;
} ListNode;

struct List {
    ListNode *head;
    ListNode *tail;
    size_t length;
};

/* Public API */
List *list_create(void) { return calloc(1, sizeof(List)); }

void list_clear(List *list) {
    if (!list) 
        return;

    ListNode *node = list->head;
    while (node != NULL) {
        ListNode *next = node->next;
        free(node);
        node = next;
    }

    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
}


void list_destroy(List **list) {
    if (list == NULL || *list == NULL) return;

    list_clear(*list);

    free(*list);
    *list = NULL;
}

/* list state */
bool list_is_empty(const List *list) { return !list || list->length == 0; }
size_t list_length(const List *list) { return !list ? 0 : list->length; }

/* Internal helpers */
ListNode *node_create(int value) {
    ListNode *node = malloc(sizeof(*node));
    if (!node) return NULL;

    node->value = value;
    node->next = NULL;

    return node;
}

/* TODO:Check */
bool list_push_front(List *list, int value) {
    if (!list) 
        return false;

    ListNode *node = node_create(value);
    if (!node) return false;

    node->next = list->head;
    list->head = node;

    if (!list->tail) list->tail = node;
    list->length++;

    return true;
}


bool list_push_back(List *list, int value) {
    if (!list) 
        return false;

    ListNode *node = node_create(value);
    if (!node) return false;

    if (!list->tail) 
        list->head = node;
    else 
        list->tail->next = node;
    list->tail = node;
    list->length++;

    return true;
}

/// @TODO: Check
bool list_pop_front(List *list, int *out_value) {
    if (list_is_empty(list)) return false;

    ListNode *node = list->head;
    if (out_value) 
        *out_value = node->value;

    list->head = node->next;
    if (!list->head) 
        list->tail = NULL;
    list->length--;
    free(node);
    return true;
}


bool list_pop_back(List *list, int *out_value) {
    if (list_is_empty(list)) return false;

    ListNode *node = list->tail;

    if (out_value) 
        *out_value = node->value;

    if (list->head == node) {
        list->head = NULL;
        list->tail = NULL;
    } else {
        ListNode *previous = list->head;
        while (previous->next != node) {
            previous = previous->next;
        }
        previous->next = NULL;
        list->tail = previous;
    }
    list->length--;
    free(node);

    return true;
}


static bool remove_value(List *list, int value, bool last_match) {
    if (list_is_empty(list)) 
        return false;

    ListNode *match = NULL;
    ListNode *match_previous = NULL;
    ListNode *previous = NULL;

    for (ListNode *node = list->head; node != NULL; node = node->next) {
        if (node->value == value) {
            match = node;
            match_previous = previous;
            if (!last_match) 
                break;
        }
        previous = node;
    }
    if (!match) return false;

    if (!match_previous) 
        list->head = match->next;
    else 
        match_previous->next = match->next;

    if (list->tail == match) 
        list->tail = match_previous;

    list->length--;
    free(match);

    return true;
}


bool list_remove_first(List *list, int value) { 
    return remove_value(list, value, false); 
}


bool list_remove_last(List *list, int value) { 
    return remove_value(list, value, true); 
}

/* utilities */
void list_print(const List *list) {
    putchar('[');
    if (list) {
        for (
            const ListNode *node = list->head; 
            node != NULL; 
            node = node->next 
        ){
            printf("%d%s", node->value, node->next == NULL ? "" : ", ");
        }
    }
    puts("]");
}

#include "../include/queue.h"

#include <stdio.h>
#include <stdlib.h>

/* define a queue instance (each Queue owns its state) */
typedef struct QueueNode {
    int value;
    struct QueueNode *next;
} QueueNode;

struct Queue {
    QueueNode *head;
    QueueNode *tail;
    size_t length;
};

Queue *queue_create(void) { 
    return calloc(1, sizeof(Queue)); 
}

bool queue_is_empty(const Queue *queue) { 
    return !queue || queue->length == 0; 
}

size_t queue_length(const Queue *queue) { return !queue ? 0 : queue->length; }

bool queue_enqueue(Queue *queue, int value) {
    if (!queue) 
        return false;

    QueueNode *node = malloc(sizeof(*node));
    if (!node) 
        return false;

    node->value = value;
    node->next = NULL;

    if (!queue->tail) 
        queue->head = node;
    else 
        queue->tail->next = node;

    queue->tail = node;
    queue->length++;

    return true;
}


bool queue_dequeue(Queue *queue, int *out_value) {
    if (queue_is_empty(queue)) 
        return false;

    QueueNode *node = queue->head;
    if (out_value != NULL) 
        *out_value = node->value;

    queue->head = node->next;
    if (!queue->head) 
        queue->tail = NULL;
    queue->length--;

    free(node);
    return true;
}


void queue_clear(Queue *queue) {
    if (!queue) 
        return;
    int ignored = 0;
    while (queue_dequeue(queue, &ignored)) { }
}


void queue_destroy(Queue **queue) {
    if (queue == NULL || *queue == NULL) 
        return;

    queue_clear(*queue);
    free(*queue);

    *queue = NULL;
}


void queue_print(const Queue *queue) {
    putchar('[');
    if (queue) {
        for (
            const QueueNode *node = queue->head; 
            node != NULL; 
            node = node->next
        ) {
            printf("%d%s", node->value, node->next == NULL ? "" : ", ");
        }
    }
    puts("]");
}

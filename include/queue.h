#ifndef _DATA_STRUCTURES_QUEUE_H_
    #define _DATA_STRUCTURES_QUEUE_H_

    #include <stdbool.h>
    #include <stddef.h>

    typedef struct Queue Queue;

    /* Lifecycle */
    Queue *queue_create(void);
    void queue_destroy(Queue **queue);

    /* Capacity */
    bool queue_is_empty(const Queue *queue);
    size_t queue_length(const Queue *queue);

    /* modifiers */
    bool queue_enqueue(Queue *queue, int value);
    bool queue_dequeue(Queue *queue, int *out_value);
    void queue_clear(Queue *queue);
    void queue_print(const Queue *queue);
    // TODO - fonctions de gestion du n-ieme element

#endif /* _DATA_STRUCTURES_QUEUE_H_ */

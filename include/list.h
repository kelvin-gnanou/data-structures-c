#ifndef _DATA_STRUCTURES_LIST_H_
    #define _DATA_STRUCTURES_LIST_H_

    #include <stdbool.h>
    #include <stddef.h>

    typedef struct List List;

    /* Lifecycle */
    List *list_create(void);
    void list_destroy(List **list);
    void list_clear(List *list);

    /* Capacity */
    bool list_is_empty(const List *list);
    size_t list_length(const List *list);

    /* utilities */
    void list_print(const List *list);

    /* modifiers */
    bool list_push_front(List *list, int value);
    bool list_push_back(List *list, int value);
    bool list_pop_front(List *list, int *out_value);
    bool list_pop_back(List *list, int *out_value);
    bool list_remove_first(List *list, int value);
    bool list_remove_last(List *list, int value);

#endif /* _DATA_STRUCTURES_LIST_H_ */

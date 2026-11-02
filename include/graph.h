#ifndef _DATA_STRUCTURES_GRAPH_H_
    #define _DATA_STRUCTURES_GRAPH_H_

    #include <stdbool.h>
    #include <stddef.h>

    typedef struct Graph Graph;

    /* Graph definition */
    Graph *graph_create(size_t vertex_count, bool directed);
    void graph_destroy(Graph **graph);
    size_t graph_vertex_count(const Graph *graph);
    bool graph_add_edge(Graph *graph, size_t source, size_t destination);
    void graph_print(const Graph *graph);

#endif /* _DATA_STRUCTURES_GRAPH_H_ */

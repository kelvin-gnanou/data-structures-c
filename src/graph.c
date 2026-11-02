/**
 * @file   : graph.c
 * @brief  : graph implemented
 * @author : Kelvin GNANOU
 * @date   : 2026/06/14 11:29
 * @todo   : check if there are some doubly in the list before add edge
 */

#include "../include/graph.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct Neighbor {
    size_t vertex;
    struct Neighbor *next;
} Neighbor;

struct Graph {
    size_t vertex_count;
    bool directed;
    Neighbor **adjacency;
};

/* Definitions */
Graph *graph_create(size_t vertex_count, bool directed) {
    Graph *graph = calloc(1, sizeof(*graph));
    if (!graph) 
        return NULL;

    if (vertex_count) {
        graph->adjacency = calloc(vertex_count, sizeof(*(graph->adjacency)));
        if (!graph->adjacency) {
            free(graph);
            return NULL;
        }
    }
    graph->vertex_count = vertex_count;
    graph->directed = directed;

    return graph;
}


size_t graph_vertex_count(const Graph *graph) {
    return !graph ? 0 : graph->vertex_count;
}


bool add_directed_edge(Graph *graph, size_t source, size_t destination) {
    Neighbor *node = malloc(sizeof(*node));
    if (!node) 
        return false;

    node->vertex = destination;
    node->next = graph->adjacency[source];
    graph->adjacency[source] = node;

    return true;
}


bool graph_add_edge(Graph *graph, size_t source, size_t destination) {
    if (!graph 
        || source >= graph->vertex_count 
        || destination >= graph->vertex_count){
            return false;
        }

    if (!add_directed_edge(graph, source, destination)) return false;

    if (!graph->directed && !add_directed_edge(graph, destination, source)) {
        Neighbor *added = graph->adjacency[source];
        graph->adjacency[source] = added->next;

        free(added);
        return false;
    }
    return true;
}


void graph_destroy(Graph **graph) {
    if (graph == NULL || *graph == NULL) return;

    for (size_t i = 0; i < (*graph)->vertex_count; ++i) {
        Neighbor *node = (*graph)->adjacency[i];
        while (node) {
            Neighbor *next = node->next;
            free(node);
            node = next;
        }
    }

    free((*graph)->adjacency);
    free(*graph);

    *graph = NULL;
}


void graph_print(const Graph *graph) {
    if (!graph) {
        puts("(graphe nul)");
        return;
    }
    for (size_t i = 0; i < graph->vertex_count; ++i) {
        printf("%zu :", i);
        for (
            const Neighbor *node = graph->adjacency[i]; 
            node != NULL; node = node->next
        ){
            printf(" %zu", node->vertex);
        }
        putchar('\n');
    }
}

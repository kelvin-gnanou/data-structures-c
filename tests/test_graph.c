/**
 * @file: test_graph.c
 * @brief: test graph implementation
 * @author: GNANOU Kelvin
 * @date: 02-11-2026
 * @note:
 * @TODO:
 */

#include <assert.h>   // assert
#include <stddef.h>   // NULL
#include <stdio.h>    // fputs, stdout

#include "../include/graph.h"

#define ASSERT_TRUE(x) assert(x)

void test_graph(void){
    Graph *graph = graph_create(3, false);
    ASSERT_TRUE(graph != NULL && "ERROR: graph creation failed !");
    ASSERT_TRUE(graph_vertex_count(graph) == 3 && "ERROR: graph vertex count is not 3 !");
    
    ASSERT_TRUE(graph_add_edge(graph, 0, 2) && "ERROR: fail to add edge 0-2 !");
    ASSERT_TRUE(!graph_add_edge(graph, 0, 3) && "ERROR: invalid vertex was accepted !");

    graph_destroy(&graph);
    ASSERT_TRUE(graph == NULL && "ERROR: graph was not destroyed !");

    graph = graph_create(0, true);
    ASSERT_TRUE(graph != NULL && "ERROR: empty graph creation failed !");
    ASSERT_TRUE(!graph_add_edge(graph, 0, 0) && "ERROR: edge added to empty graph !");
    graph_destroy(&graph);

    fputs("func: void test_graph(void) end succefully ...\n", stdout);
}

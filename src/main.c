#include "../include/stack.h"
#include "../include/queue.h"
#include "../include/list.h"
#include "../include/graph.h"
#include "../include/binary_tree.h"

#include <stdio.h>

/**
 * @brief  : graph
 * @author : Kelvin GNANOU
 * @date   : 2026/06/14 11:17
 * @note   :
 * @todo   :
 */
static void demo_graph(void) {
    Graph *graph = graph_create(4, false);

    if (!graph) { 
        puts("Allocation du graphe impossible."); 
        return; 
    }
    graph_add_edge(graph, 0, 2);
    graph_add_edge(graph, 0, 1);
    graph_add_edge(graph, 2, 3);

    graph_print(graph);

    graph_destroy(&graph);
}


static void demo_tree(void) {
    BinaryTree tree = tree_create();

    const int values[] = {6, 9, 0, -4, 12};
    const size_t size = sizeof(values) / sizeof(values[0]);

    for (size_t i = 0; i < size; i++){
        if (!tree_insert(&tree, values[i])) {
            puts("Allocation de l'arbre impossible.");
        }
    }
        
    printf("Parcours infixe : ");
    tree_print_inorder(tree);
    printf("Noeuds : %zu | hauteur : %zu\n", 
        tree_size(tree), 
        tree_height(tree));
        
    tree_destroy(&tree);
}


/**
 * @brief  : List implementation
 * @author : Kelvin GNANOU
 * @date   : 2026/04/09 00:01
 * @note   :
 * @todo   :
 */
static void demo_list(void) {
    List *list = list_create();
    if (!list) { 
        puts("Allocation de la liste impossible."); 
        return; 
    }
    list_push_back(list, 4);
    list_push_back(list, 9);
    list_push_front(list, -2);

    list_print(list);

    list_destroy(&list);
}


static void demo_queue(void) {
    Queue *queue = queue_create();
    if (!queue) { 
        puts("Allocation de la file impossible."); 
        return; 
    }

    queue_enqueue(queue, 14);
    queue_enqueue(queue, -34);

    queue_print(queue);

    queue_destroy(&queue);
}

/**
*@brief: the main file of stack implementation
*/
static void demo_stack(void) {
    Stack *stack = stack_create();
    if (!stack) { 
        puts("Allocation de la pile impossible."); 
        return; 
    }
    stack_push(stack, 11);
    stack_push(stack, -13);
    stack_push(stack, 15);

    stack_print(stack);

    stack_destroy(&stack);
}

static void menu(void) {
    puts("\nStructures de donnees en C");
    puts("1. Arbre binaire de recherche");
    puts("2. Graphe (listes d'adjacence)");
    puts("3. Liste chainee");
    puts("4. File");
    puts("5. Pile");
    puts("0. Quitter");
    printf("Choix>");
}

static void choice(int choice) {
    switch (choice) {
        case 1: demo_tree(); break;
        case 2: demo_graph(); break;
        case 3: demo_list(); break;
        case 4: demo_queue(); break;
        case 5: demo_stack(); break;
        case 0: break;
        default: puts("Choix inconnu."); break;
    }
}


int main(void) {
    int ch = 0;
    do {
        menu();

        if (scanf("%d", &ch) != 1) {
            puts("Saisie invalide.");
            return 1;
        }

        choice(ch);
    } while (ch != 0);

    return 0;
}

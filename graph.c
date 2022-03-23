#include "graph.h"
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

graph *Init_Graph(GRAPH_ERR *err) {

    graph *cgraph = (graph *)malloc(sizeof(graph));

    if (cgraph == NULL) {
        fprintf(stderr, "Not enough memory\n");
        if (err != NULL) {
            *err = EMALLOC;
        }
        return NULL;
    }

    cgraph->arr = (int *)malloc(0 * (sizeof(int)));

    if (cgraph->arr == NULL) {
        fprintf(stderr, "Not enough memory\n");
        if(err != NULL) {
            *err = EMALLOC;
        }
        return NULL;
    }

    cgraph->size = 0;

    *err = ESUCCESS;
    return cgraph;
}

void Remove_Graph(graph *graph, GRAPH_ERR *err) {

    if (graph == NULL) {
        fprintf(stderr, "Invalid argument: graph\n");
        if(err != NULL) {
            *err = EINVARG;
        }
        return;
    }

    if (graph->arr) {
        free(graph->arr);
    }

    free(graph);
    *err = ESUCCESS;
}

void Push_Edge(graph *graph, int val, int i, int j, GRAPH_ERR *err) {

    if (graph == NULL) {
        fprintf(stderr, "Invalid argument: graph\n");
        if (err != NULL) {
            *err = EINVARG;
        }
        return;
    }

    if (i <= 0) {
        fprintf(stderr, "Invalid argument: i\n");
        if (err != NULL) {
            *err = EINVARG;
        }
        return;
    }

    if (j <= 0) {
        fprintf(stderr, "Invalid argument: j\n");
        if (err != NULL) {
            *err = EINVARG;
        }
        return;
    }

    if (graph->size < i || graph->size < j) {
        int max;
        if (i < j) {
            max = j;
        } else {
            max = i;
        }
        graph->arr = (int *) realloc(graph->arr,2 * (max * max) * sizeof(int));

        if (graph->arr == NULL) {
            fprintf(stderr, "Not enough memory\n");
            if(err != NULL) {
                *err = EMALLOC;
            }
            return;
        }

        for (int k = 2 * graph->size * graph->size; k < 2 * max * max; ++k) {
            if (k % 2 == 0) {
                graph->arr[k] = -1;
            } else {
                graph->arr[k] = 0;
            }
        }
        graph->size = max;
    }

    int temp;
    if (i < j) {
        temp = 2 * ((j - 1) * (j - 1) + i - 1);
    } else if (j < i) {
        temp = 2 * (i * (i - 1) + j - 1);
    } else {
        temp = 2 * (i * i - 1);
    }
    *err = ESUCCESS;
    graph->arr[temp] = val;
    graph->arr[temp + 1] = 1;
}

int Pop_Edge(graph *graph, int i, int j, GRAPH_ERR *err) {

    if (graph == NULL) {
        fprintf(stderr, "Invalid argument: graph\n");
        if (err != NULL)
            *err = EINVARG;
        return INT_MAX;
    }

    if (i > graph->size || i <= 0) {
        fprintf(stderr, "Invalid argument: i\n");
        if (err != NULL) {
            *err = EINVARG;
        }
        return INT_MAX;
    }

    if (j > graph->size || j <= 0) {
        fprintf(stderr, "Invalid argument: j\n");
        if (err != NULL) {
            *err = EINVARG;
        }
        return INT_MAX;
    }

    int temp;
    if (i < j) {
        temp = 2 * ((j - 1) * (j - 1) + i - 1);
    } else if (j < i) {
        temp = 2 * (i * (i - 1) + j - 1);
    } else {
        temp = 2 * (i * i - 1);
    }

    int val;
    if (graph->arr[temp + 1] == 1) {
        val = graph->arr[temp];
    } else {
        val = INT_MAX;
    }

    *err = ESUCCESS;
    return val;
}

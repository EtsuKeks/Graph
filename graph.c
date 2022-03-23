#include "graph.h"
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

graph *Init_Graph(int size, GRAPH_ERR *err) {
    if (size < 0) {
        fprintf(stderr, "Invalid argument: size\n");
        if (err != NULL) {
            *err = EINVARG;
        }
        return NULL;
    }

    graph *cgraph = (graph *)malloc(sizeof(graph));
    if (cgraph == NULL) {
        fprintf(stderr, "Not enough memory\n");
        if (err != NULL) {
            *err = EMALLOC;
        }
        return NULL;
    }

    cgraph->arr = (int *)malloc(sizeof(int) * size * size);
    if (cgraph->arr == NULL) {
        fprintf(stderr, "Not enough memory\n");
        if(err != NULL) {
            *err = EMALLOC;
        }
        return NULL;
    }

    cgraph->size = size;

    for (int i = 0; i < size * size; ++i) {
        cgraph->arr[i] = -1;
    }

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

    if (graph->size == 0) {
        fprintf(stderr, "Graph is empty\n");
        if (err != NULL) {
            *err = EEMPTY;
        }
        return;
    }

    if (i > graph->size || i <= 0) {
        fprintf(stderr, "Invalid argument: i\n");
        if (err != NULL) {
            *err = EINVARG;
        }
        return;
    }

    if (j > graph->size || j <= 0) {
        fprintf(stderr, "Invalid argument: j\n");
        if (err != NULL) {
            *err = EINVARG;
        }
        return;
    }

    if (val < 0) {
        fprintf(stderr, "Invalid argument: val; It's not allowed to set val < 0");
        if (err != NULL) {
            *err = EINVARG;
        }
        return;
    }

    int temp;
    if (i < j) {
        temp = (j - 1) * (j - 1) + i - 1;
    } else if (j < i) {
        temp = i * (i - 1) + j - 1;
    } else {
        temp = i * i - 1;
    }
    *err = ESUCCESS;
    graph->arr[temp] = val;
}

int Pop_Edge(graph *graph, int i, int j, GRAPH_ERR *err) {
    if (graph == NULL) {
        fprintf(stderr, "Invalid argument: graph\n");
        if (err != NULL)
            *err = EINVARG;
        return INT_MAX;
    }

    if (graph->size == 0) {
        fprintf(stderr, "Graph is empty\n");
        if (err != NULL)
            *err = EEMPTY;
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
        temp = (j - 1) * (j - 1) + i - 1;
    } else if (j > i) {
        temp = i * (i - 1) + j - 1;
    } else {
        temp = i * i - 1;
    }
    *err = ESUCCESS;
    int val = graph->arr[temp];
    if (val >= 0) {
        return val;
    } else {
        return -1;
    }
}

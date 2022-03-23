#include "graph.h"
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

graph *Init_Graph(int size) {
    graph *cgraph = (graph *)malloc(sizeof(graph));

    cgraph->arr = (int *)malloc(sizeof(int) * size * size);

    cgraph->size = size;

    for (int i = 0; i < size * size; ++i) {
        cgraph->arr[i] = -1;
    }

    return cgraph;
}

void Remove_Graph(graph *graph) {
    if (graph->arr) {
        free(graph->arr);
    }
    free(graph);
}



void Push_Edge(graph *graph, int val, int i, int j) {

    int temp;
    if (i < j) {
        temp = (j - 1) * (j - 1) + i - 1;
    } else if (j < i) {
        temp = i * (i - 1) + j - 1;
    } else {
        temp = i * i - 1;
    }
    graph->arr[temp] = val;
}

int Pop_Edge(graph *graph, int i, int j) {

    int temp;
    if (i < j) {
        temp = (j - 1) * (j - 1) + i - 1;
    } else if (j > i) {
        temp = i * (i - 1) + j - 1;
    } else {
        temp = i * i - 1;
    }
    int val = graph->arr[temp];
    if (val >= 0) {
        return val;
    } else {
        return -1;
    }
}

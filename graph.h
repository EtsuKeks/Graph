#ifndef _GRAPH_H_
#define _GRAPH_H_

typedef struct graph {
    int size;
    int *arr;
} graph;

typedef enum {
    ESUCCESS = 0,
    EMALLOC,
    EEMPTY,
    EINVARG
} GRAPH_ERR;

graph *Init_Graph(int size);

void Remove_Graph(graph *graph);

int Pop_Edge(graph *graph, int i, int j);

void Push_Edge(graph *graph, int val, int i, int j);

#endif  // _GRAPH_H_

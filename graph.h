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

graph *Init_Graph(int size, GRAPH_ERR *err);

void Remove_Graph(graph *graph, GRAPH_ERR *err);

int Pop_Edge(graph *graph, int i, int j, GRAPH_ERR *err);

void Push_Edge(graph *graph, int val, int i, int j, GRAPH_ERR *err);

#endif  // _GRAPH_H_

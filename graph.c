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

void Print(graph *graph, GRAPH_ERR *err) {

    if (graph == NULL) {
        fprintf(stderr, "Invalid argument: graph\n");
        if (err != NULL)
            *err = EINVARG;
        return;
    }

    for (int i = 1; i <= graph->size; ++i) {
        for (int j = 1; j <= graph->size; ++j) {
            int temp;
            if (i < j) {
                temp = 2 * ((j - 1) * (j - 1) + i - 1);
            } else if (j < i) {
                temp = 2 * (i * (i - 1) + j - 1);
            } else {
                temp = 2 * (i * i - 1);
            }
            if (graph->arr[temp + 1] == 1) {
                printf("(%d, %d) = %d\n", i, j, graph->arr[temp]);
            }
        }
    }

    *err = ESUCCESS;
}


void Print_Shortest_Paths(graph *graph, int vertex, GRAPH_ERR *err){

    if (graph == NULL || graph->size == 0 || graph->size == 1) {
        fprintf(stderr, "Invalid argument: graph\n");
        if (err != NULL)
            *err = EINVARG;
        return;
    }

    if (vertex <= 0 || vertex > graph->size) {
        fprintf(stderr, "Invalid argument: vertex\n");
        if (err != NULL)
            *err = EINVARG;
        return;
    }

    int *edges, size = 0;
    edges = (int *)malloc(0 * (sizeof(int)));

    if (edges == NULL) {
        fprintf(stderr, "Not enough memory\n");
        if (err != NULL) {
            *err = EMALLOC;
        }
    	free(edges);
	    return;
    }

    for (int i = 1; i <= graph->size; ++i) {
        for (int j = 1; j <= graph->size; ++j) {
            int temp;
            if (i < j) {
                temp = 2 * ((j - 1) * (j - 1) + i - 1);
            } else if (j < i) {
                temp = 2 * (i * (i - 1) + j - 1);
            } else {
                temp = 2 * (i * i - 1);
            }
            if (graph->arr[temp + 1] == 1) {
                edges = (int *) realloc(edges,  (3 + size) * sizeof(int));

                if (edges == NULL) {
                    fprintf(stderr, "Not enough memory\n");
                    if (err != NULL) {
                        *err = EMALLOC;
                    }
                    free(edges);
					return;
                }
                    edges[size] = i;
                    edges[size + 1] = j;
                    edges[size + 2] = graph->arr[temp];
                    size += 3;
            }
        }
    }

    int *array;
    array = (int *)malloc((graph->size + 1) * (sizeof(int)));

    if (array == NULL) {
        fprintf(stderr, "Not enough memory\n");
        if(err != NULL) {
            *err = EMALLOC;
        }
		free(edges);
		free(array);
        return;
    }

    array[0] = 0;
    for (int i = 1; i <= graph->size; ++i) {
        array[i] = (INT_MAX - 1) / 2;
    }
    array[vertex] = 0;

    for (int i = 0; i < graph->size - 1; ++i) {
        for (int j = 0; j < size / 3; ++j) {
            int n = edges[3 * j], m = edges[3 * j + 1], buff = edges[3 * j + 2];
            if (n == m && buff < 0) {
                fprintf(stderr, "Invalid argument: graph (graph cannot contain negative loops)\n");
                if (err != NULL)
                    *err = EINVARG;
                free(edges);
				free(array);
				return;
            } else {
                if (array[m] > array[n] + buff) {
                    array[m] = array[n] + buff;
                }
            }
        }
    }

    int indicator = 0;

    for (int j = 0; j < size / 3; ++j) {
        int n = edges[3 * j], m = edges[3 * j + 1], buff = edges[3 * j + 2];
        if (array[m] > array[n] + buff) {
            indicator = 1;
            break;
        }
    }

    if (indicator) {
        printf("There's a negative length cycle");
    } else {
        for (int i = 1; i <= graph->size; ++i) {
            if (vertex == i) {
                continue;
            } else if (array[i] < ((INT_MAX - 1) / 2 - 1) / 2) {
                printf("Path from %d to %d is at least %d\n", vertex, i, array[i]);
            } else {
                printf("Path from %d to %d doesn't exist\n", vertex, i);
            }
        }
    }
    *err = ESUCCESS;
    free(edges);
    free(array);
}

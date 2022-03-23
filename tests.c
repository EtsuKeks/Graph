#include "graph.h"
#include <stdio.h>

int main()
{
    graph *graph = NULL;
    GRAPH_ERR err;

    graph = Init_Graph(-1, &err);
    if (err != EINVARG)
        fprintf(stdout, "Test_1\t->\tFAILED\n");
    else
        fprintf(stdout, "Test_1\t->\tPASSED\n");

    graph = Init_Graph(5, &err);
    if (graph == NULL)
        fprintf(stdout, "Test_2\t->\tFAILED\n");
    else
        fprintf(stdout, "Test_2\t->\tPASSED\n");

    Push_Edge(NULL, 1, 1, 1, &err);
    if (err != EINVARG)
        fprintf(stdout, "Test_3.1\t->\tFAILED\n");
    else
        fprintf(stdout, "Test_3.1\t->\tPASSED\n");

    Push_Edge(graph, 1, 2, 2, &err);
    if (err == EINVARG)
        fprintf(stdout, "Test_3.2\t->\tFAILED\n");
    else
        fprintf(stdout, "Test_3.2\t->\tPASSED\n");

    Push_Edge(graph, -1, 1, 1, &err);
    if (err != EINVARG)
        fprintf(stdout, "Test_3.3\t->\tFAILED\n");
    else
        fprintf(stdout, "Test_3.3\t->\tPASSED\n");

    Push_Edge(graph, 1, -1, 1, &err);
    if (err == EINVARG)
        fprintf(stdout, "Test_3.4\t->\tPASSED\n");
    else
        fprintf(stdout, "Test_3.4\t->\tFAILED\n");

    Push_Edge(graph, 1, 1, -1, &err);
    if (err == EINVARG)
        fprintf(stdout, "Test_3.5\t->\tPASSED\n");
    else
        fprintf(stdout, "Test_3.5\t->\tFAILED\n");

    Push_Edge(graph, 1, 10, 1, &err);
    if (err == EINVARG)
        fprintf(stdout, "Test_3.6\t->\tPASSED\n");
    else
        fprintf(stdout, "Test_3.6\t->\tFAILED\n");

    Pop_Edge(NULL, 1, 1, &err);
    if (err != EINVARG)
        fprintf(stdout, "Test_4.1\t->\tFAILED\n");
    else
        fprintf(stdout, "Test_4.1\t->\tPASSED\n");

    Pop_Edge(graph, 2, 2, &err);
    if (err == EINVARG)
        fprintf(stdout, "Test_4.2\t->\tFAILED\n");
    else
        fprintf(stdout, "Test_4.2\t->\tPASSED\n");

    Pop_Edge(graph, -1, 1, &err);
    if (err != EINVARG)
        fprintf(stdout, "Test_4.3\t->\tFAILED\n");
    else
        fprintf(stdout, "Test_4.3\t->\tPASSED\n");

    Pop_Edge(graph, 1, -1, &err);
    if (err != EINVARG)
        fprintf(stdout, "Test_4.4\t->\tFAILED\n");
    else
        fprintf(stdout, "Test_4.4\t->\tPASSED\n");

    Pop_Edge(graph, 10, 1, &err);
    if (err != EINVARG)
        fprintf(stdout, "Test_4.5\t->\tFAILED\n");
    else
        fprintf(stdout, "Test_4.5\t->\tPASSED\n");

    int temp = Pop_Edge(graph, 2, 2, &err);
    if (temp != 1)
        fprintf(stdout, "Test_4.6\t->\tFAILED\n");
    else
        fprintf(stdout, "Test_4.6\t->\tPASSED\n");

    return 0;
}

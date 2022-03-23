#include "graph.h"
#include <stdio.h>

int main() {
    graph *graph = NULL;
    GRAPH_ERR err;

    {

        graph = Init_Graph(&err);
        if (err == EMALLOC)
            fprintf(stdout, "Test_1\t->\tFAILED\n");
        else
            fprintf(stdout, "Test_1\t->\tPASSED\n");

    }

    {
        Push_Edge(NULL, 1, 1, 1, &err);
        if (err != EINVARG)
            fprintf(stdout, "Test_2.1\t->\tFAILED\n");
        else
            fprintf(stdout, "Test_2.1\t->\tPASSED\n");

        Push_Edge(graph, -1, 1, 2, &err);
        if (err == EINVARG)
            fprintf(stdout, "Test_2.2\t->\tFAILED\n");
        else
            fprintf(stdout, "Test_2.2\t->\tPASSED\n");

        Push_Edge(graph, 1, 1, 2, &err);
        if (err == EINVARG)
            fprintf(stdout, "Test_2.3\t->\tFAILED\n");
        else
            fprintf(stdout, "Test_2.3\t->\tPASSED\n");

        Push_Edge(graph, 1, 3, 1, &err);
        if (err == EINVARG)
            fprintf(stdout, "Test_2.4\t->\tFAILED\n");
        else
            fprintf(stdout, "Test_2.4\t->\tPASSED\n");

    }


    {

        Pop_Edge(NULL, 1, 1, &err);
        if (err != EINVARG)
            fprintf(stdout, "Test_3.1\t->\tFAILED\n");
        else
            fprintf(stdout, "Test_3.1\t->\tPASSED\n");

        Pop_Edge(graph, 2, 2, &err);
        if (err == EINVARG)
            fprintf(stdout, "Test_3.2\t->\tFAILED\n");
        else
            fprintf(stdout, "Test_3.2\t->\tPASSED\n");

        Pop_Edge(graph, -1, 1, &err);
        if (err != EINVARG)
            fprintf(stdout, "Test_3.3\t->\tFAILED\n");
        else
            fprintf(stdout, "Test_3.3\t->\tPASSED\n");

        Pop_Edge(graph, 1, -1, &err);
        if (err != EINVARG)
            fprintf(stdout, "Test_3.4\t->\tFAILED\n");
        else
            fprintf(stdout, "Test_3.4\t->\tPASSED\n");

        Pop_Edge(graph, 10, 1, &err);
        if (err != EINVARG)
            fprintf(stdout, "Test_3.5\t->\tFAILED\n");
        else
            fprintf(stdout, "Test_3.5\t->\tPASSED\n");

        Pop_Edge(graph, 1, 10, &err);
        if (err != EINVARG)
            fprintf(stdout, "Test_3.6\t->\tFAILED\n");
        else
            fprintf(stdout, "Test_3.6\t->\tPASSED\n");

        int temp = Pop_Edge(graph, 1, 2, &err);
        if (temp != 1)
            fprintf(stdout, "Test_3.7\t->\tFAILED\n");
        else
            fprintf(stdout, "Test_3.7\t->\tPASSED\n");
    }

    {

        Print(NULL, &err);
        if (err != EINVARG)
            fprintf(stdout, "Test_4.1\t->\tFAILED\n");
        else
            fprintf(stdout, "Test_4.1\t->\tPASSED\n");

        Print(graph, &err);
        if (err == EINVARG)
            fprintf(stdout, "Test_4.2\t->\tFAILED\n");
        else
            fprintf(stdout, "Test_4.2\t->\tPASSED\n");

    }


    {

        Print_Shortest_Paths(NULL, 2, &err);
        if (err != EINVARG)
            fprintf(stdout, "Test_5.1\t->\tFAILED\n");
        else
            fprintf(stdout, "Test_5.1\t->\tPASSED\n");

        Print_Shortest_Paths(graph, 4, &err);
        if (err != EINVARG)
            fprintf(stdout, "Test_5.2\t->\tFAILED\n");
        else
            fprintf(stdout, "Test_5.2\t->\tPASSED\n");

        Print_Shortest_Paths(graph, -1, &err);
        if (err != EINVARG)
            fprintf(stdout, "Test_5.3\t->\tFAILED\n");
        else
            fprintf(stdout, "Test_5.3\t->\tPASSED\n");

        Print_Shortest_Paths(graph, 2, &err);
        if (err == EINVARG)
            fprintf(stdout, "Test_5.4\t->\tFAILED\n");
        else
            fprintf(stdout, "Test_5.4\t->\tPASSED\n");

    }

    {

        Remove_Graph(NULL, &err);
        if (err != EINVARG)
            fprintf(stdout, "Test_6.1\t->\tFAILED\n");
        else
            fprintf(stdout, "Test_6.1\t->\tPASSED\n");

        Remove_Graph(graph, &err);
        if (err == EINVARG)
            fprintf(stdout, "Test_6.2\t->\tFAILED\n");
        else
            fprintf(stdout, "Test_6.2\t->\tPASSED\n");

    }

    return 0;
}


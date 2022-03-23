#include "graph.h"
#include <stdio.h>

int main() {
    graph *graph = NULL, *graph2 = NULL, *graph3 = NULL, *graph4 = NULL, *graph5 = NULL;
    GRAPH_ERR err;

    {

        graph = Init_Graph(&err);
        if (err == EMALLOC)
            fprintf(stdout, "Test_1.1\t->\tFAILED\n");
        else
            fprintf(stdout, "Test_1.1\t->\tPASSED\n");

	graph2 = Init_Graph(&err);
	if (err == EMALLOC)
	    fprintf(stdout, "Test_1.2\t->\tFAILED\n");
	else
	    fprintf(stdout, "Test_1.2\t->\tPASSED\n");

	graph3 = Init_Graph(&err);
	if (err == EMALLOC)
	    fprintf(stdout, "Test_1.3\t->\tFAILED\n");
	else
	    fprintf(stdout, "Test_1.3\t->\tPASSED\n");

	graph4 = Init_Graph(&err);
	if (err == EMALLOC)
	    fprintf(stdout, "Test_1.4\t->\tFAILED\n");
	else
	    fprintf(stdout, "Test_1.4\t->\tPASSED\n");

	graph5 = Init_Graph(&err);
	if (err == EMALLOC)
	    fprintf(stdout, "Test_1.5\t->\tFAILED\n");
	else
	    fprintf(stdout, "Test_1.5\t->\tPASSED\n");

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

        Push_Edge(graph, 1, 3, 2, &err);
        if (err == EINVARG)
            fprintf(stdout, "Test_2.4\t->\tFAILED\n");
        else
            fprintf(stdout, "Test_2.4\t->\tPASSED\n");

	Push_Edge(graph2, 2, 2, 2, &err);
        if (err == EINVARG)
            fprintf(stdout, "Test_2.5\t->\tFAILED\n");
        else
            fprintf(stdout, "Test_2.5\t->\tPASSED\n");

	Push_Edge(graph2, 2, -1, 1, &err);
        if (err != EINVARG)
            fprintf(stdout, "Test_2.6\t->\tFAILED\n");
        else
            fprintf(stdout, "Test_2.6\t->\tPASSED\n");

	Push_Edge(graph2, 2, 1, -1, &err);
        if (err != EINVARG)
            fprintf(stdout, "Test_2.7\t->\tFAILED\n");
        else
            fprintf(stdout, "Test_2.7\t->\tPASSED\n");

	Push_Edge(graph2, -1, 1, 1, &err);
        if (err == EINVARG)
            fprintf(stdout, "Test_2.8\t->\tFAILED\n");
        else
            fprintf(stdout, "Test_2.8\t->\tPASSED\n");

	Push_Edge(graph3, -1, 1, 2, &err);
        if (err == EINVARG)
            fprintf(stdout, "Test_2.9\t->\tFAILED\n");
        else
            fprintf(stdout, "Test_2.9\t->\tPASSED\n");

	Push_Edge(graph3, -1, 2, 3, &err);
        if (err == EINVARG)
            fprintf(stdout, "Test_2.10\t->\tFAILED\n");
        else
            fprintf(stdout, "Test_2.10\t->\tPASSED\n");

	Push_Edge(graph3, -1, 3, 1, &err);
        if (err == EINVARG)
            fprintf(stdout, "Test_2.11\t->\tFAILED\n");
        else
            fprintf(stdout, "Test_2.11\t->\tPASSED\n");

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

	Pop_Edge(graph, 3, 2, &err);
        if (err == EINVARG)
            fprintf(stdout, "Test_3.8\t->\tFAILED\n");
        else
            fprintf(stdout, "Test_3.8\t->\tPASSED\n");

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

        Print_Shortest_Paths(graph2, 1, &err);
        if (err != EINVARG)
            fprintf(stdout, "Test_5.5\t->\tFAILED\n");
        else
            fprintf(stdout, "Test_5.5\t->\tPASSED\n");

        Print_Shortest_Paths(graph3, 2, &err);
        if (err == EINVARG)
            fprintf(stdout, "Test_5.6\t->\tFAILED\n");
        else
            fprintf(stdout, "Test_5.6\t->\tPASSED\n");

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

        Remove_Graph(graph2, &err);
        if (err == EINVARG)
            fprintf(stdout, "Test_6.3\t->\tFAILED\n");
        else
            fprintf(stdout, "Test_6.3\t->\tPASSED\n");

        Remove_Graph(graph3, &err);
        if (err == EINVARG)
            fprintf(stdout, "Test_6.4\t->\tFAILED\n");
        else
            fprintf(stdout, "Test_6.4\t->\tPASSED\n");

        Remove_Graph(graph4, &err);
        if (err == EINVARG)
            fprintf(stdout, "Test_6.5\t->\tFAILED\n");
        else
            fprintf(stdout, "Test_6.5\t->\tPASSED\n");

        Remove_Graph(graph5, &err);
        if (err == EINVARG)
            fprintf(stdout, "Test_6.6\t->\tFAILED\n");
        else
            fprintf(stdout, "Test_6.6\t->\tPASSED\n");

    }
    return 0;
}


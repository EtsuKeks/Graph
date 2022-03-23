# Graph
## Introduction
This data structure was implemented in C as part of my training at MIPT. It has it's own error class and does not need the size fixed -- it changes dynamically.

## Functions
Apart from default functions such as gragh generating and popping an edge, it also has a "Print" and a "Print_Shortest_Paths" function. The first one basically prints your graph in a certain format, the second uses the Bellman–Ford algorithm to find the shortest paths from the given verticle. If there is a loop of a negative lenth or a cycle of a negative length, this function will inform the user about this. 

Unit test coverage 86.11%.

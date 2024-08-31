Rules for the graph Format:

1. The file format is CSV, each data entry needs to have a ',' following it (also at the end of a line).
2. The first row in the file defines the nodes in the graph, duplicates or invalid entries will be skipped.
3. A node is defined as a single character between A - Z (capital only).
4. Every row after the first one, defines an edge in the graph, the format is Node "1, Node 2, Cost,"
5. The graph is bidirectional, every edge stated will connect the nodes both ways.
6. The edges needs a cost assigned to them, if your graph doesn't have any cost for the edges, make all the edges cost 1.
7. Additonal edges that connect the same nodes, or invalid edges will be skipped.
8. There is a graph.csv file in the resource files with an example graph format.

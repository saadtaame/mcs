# mcs
A C++ implementation of Tarjan's *maximum cardinality search* algorithm for chordal graph recognition. The program assumes that the graph is undirected and connected. The program reads the number of vertices, n, and the number of edges, m, and then it reads m lines each containing a pair of vertices (x,y) meaning that there is an edge between vertex number x and vertex number y (numbering is zero-based). The program then outputs `CHORDAL` if the graph is chordal and `NOT CHORDAL` elsewise. This implementation takes time O((n+m) lg n).

Sample input/output:

input:
<pre>
4 5
0 2
0 1
1 2
2 3
3 0
</pre>

output:
<pre>
CHORDAL
</pre>

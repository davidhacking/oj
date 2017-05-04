/*
pseudocode:
function Dijkstra(Graph, source):

    create vertex set Q

    for each vertex v in Graph:             
		// Initialization
        dist[v] ← INFINITY                  
		// Unknown distance from source to v
        prev[v] ← UNDEFINED                 
		// Previous node in optimal path from source
        add v to Q                          
		// All nodes initially in Q (unvisited nodes)

    dist[source] ← 0                        // Distance from source to source
    
    while Q is not empty:
        u ← vertex in Q with min dist[u]    
		// Node with the least distance will be selected first
        remove u from Q 
        
        for each neighbor v of u:           // where v is still in Q.
            alt ← dist[u] + length(u, v)
            if alt < dist[v]:               // A shorter path to v has been found
                dist[v] ← alt 
                prev[v] ← u 

    return dist[], prev[] 
 */
#include <vector>
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

/*
 test data:
 
*/
struct Edge {
	int a;
	int b;
	int w;
} edges[100];
int Q[100];
int edges_len = 0;
int vertex_len = 0;
int main() {
	int edge_number = 0;
	scanf("%d %d", &vertex_len, &edge_number);
	edges_len = 0;
	for (int i = 0; i < edge_number; i++) {
		scanf("%d %d %d", &edges[edges_len].a, &edges[edges_len].b, 
				&edges[edges_len].w);
		edges_len++;
	}
	memset(Q, 1, edges_len * sizeof(int));
	for (int i = 0; i < vertex_len; i++) {

	}
}

#include <limits.h>
#include <iostream>
#include <stdio.h>
// Number of vertices in graph
#define V 6
using namespace std;

// Function to find the vertex with minimum distance value,
int minDistance(int dist[], bool sptSet[])
{
    
    int min = INT_MAX, min_index;

    // Find the vertex with minimum distance
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Function for print the constructed distance array
void printSolution(int dist[], int n)
{
    cout<<"Vertex   Distance from Source\n";
    for (int i = 0; i < V; i++)
        cout<<i<<"-------"<< dist[i]<<endl;
        }
// Dijkstra's single source shortest path algorithm
void dijkstra(int graph[V][V], int src)
{
    int dist[V]; // array used to store the shortest distance from source 

    bool sptSet[V]; 

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick minimum distance vertex from the set of vertices not yet processed.
        int u = minDistance(dist, sptSet);

        // Mark the  vertex as processed
        sptSet[u] = true;

        // Update dist[v] only if it is not in sptSet, there is an edge from u to v,and the total weight of path from src to v through u is smaller than current value of dist[v]
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // Print the constructed distance array
    printSolution(dist, V);
}

int main()
{
    int graph[V][V] = {{0, 10, 0, 0, 15, 5},
                       {10, 0, 10, 30, 0, 0},
                       {0, 10, 0, 12, 5, 0},
                       {0, 30, 12, 0, 0, 20},
                       {15, 0, 5, 0, 0, 0},
                       {5, 0, 0, 20, 0, 0}};

    int source_node = 5;
    cout<<"Source is  "<< source_node<<endl;
    dijkstra(graph, source_node);

    return 0;
}

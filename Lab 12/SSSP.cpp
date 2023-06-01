#include <limits.h>
#include <iostream>
#include <stdio.h>
// Number of vertices in graph
#define V 6
using namespace std;

// Function to find the vertex with minimum distance value,
int minDistance(int time[], bool VertexVisited[])
{
    
    int min = INT_MAX, min_index;

    // Find the vertex with minimum distance
    for (int v = 0; v < V; v++)
        if (VertexVisited[v] == false && time[v] <= min)
            min = time[v], min_index = v;

    return min_index;
}

// Function for print the constructed distance array
void printSolution(int time[], int n)
{
    cout<<"Vertex   Distance from Source\n";
    for (int i = 0; i < V; i++)
        cout<<i<<"-------"<< time[i]<<endl;
        }
// Dijkstra's single source shortest path algorithm
void dijkstra(int graph[V][V], int src)
{
    int time[V]; // array used to store the shortest distance from source 

    bool VertexVisited[V]; 

    // Initialize all distances as INFINITE and VertexVisited[] as false
    for (int i = 0; i < V; i++)
        time[i] = INT_MAX, VertexVisited[i] = false;

    // Distance of source vertex from itself is always 0
    time[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick minimum distance vertex from the set of vertices not yet processed.
        int u = minDistance(time, VertexVisited);

        // Mark the  vertex as processed
        VertexVisited[u] = true;

        // Update time[v] only if it is not in VertexVisited, there is an edge from u to v,and the total weight of path from src to v through u is smaller than current value of time[v]
        for (int v = 0; v < V; v++)
            if (!VertexVisited[v] && graph[u][v] && time[u] != INT_MAX
                && time[u] + graph[u][v] < time[v])
                time[v] = time[u] + graph[u][v];
    }

    // Print the constructed distance array
    printSolution(time, V);
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

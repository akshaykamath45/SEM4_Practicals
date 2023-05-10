#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#define vertices 9

int findShortestDistance(int distance[], bool visited[])
{
    int min = INT_MAX, minIndex;
    for (int i = 0; i < vertices; i++)
    {
        if (visited[i] == false && distance[i] <= min)
        {
            min = distance[i];
            minIndex = i;
        }
    }
    return minIndex;
}
void initializeSingleSource(int distance[], int parent[], bool visited[], int source)
{
    for (int i = 0; i < vertices; i++)
    {
        distance[i] = INT_MAX;
        parent[i] = -1;
        visited[i] = false;
    }
    distance[source] = 0;
}

void dijkstra(int graph[][vertices], int distance[], int parent[], bool visited[], int source)
{

    for (int count = 0; count < vertices - 1; count++)
    {
        int u = findShortestDistance(distance, visited);
        for (int v = 0; v < vertices; v++)
        {
            if (distance[u] + graph[u][v] < distance[v] && graph[u][v])
            {
                distance[v] = distance[u] + graph[u][v];
                parent[v] = u;
            }
        }
        visited[u] = true;
    }
}

void printTable(int distance[], int parent[])
{
    printf("Vertex\tDistance  Parent\n");
    for (int i = 0; i < vertices; i++)
    {
        printf("%d\t%d\t  %d\n", i, distance[i], parent[i]);
    }
}

int main()
{
    int graph[vertices][vertices] = {{0, 11, 0, 0, 0, 0, 0, 8, 0},  // 0
                                     {11, 0, 8, 0, 0, 0, 0, 11, 0}, // 1
                                     {0, 8, 0, 7, 0, 4, 0, 0, 2},   // 2
                                     {0, 0, 7, 0, 9, 14, 0, 0, 0},  // 3
                                     {0, 0, 0, 9, 0, 10, 0, 0, 0},  // 4
                                     {0, 0, 4, 14, 10, 0, 2, 0, 0}, // 5
                                     {0, 0, 0, 0, 0, 2, 0, 1, 6},   // 6
                                     {8, 11, 0, 0, 0, 0, 1, 0, 7},  // 7
                                     {0, 0, 2, 0, 0, 0, 6, 7, 0}};  // 8
    int distance[30];
    int parent[30];
    bool visited[30];
    int source = 0;
    initializeSingleSource(distance, parent, visited, source);
    dijkstra(graph, distance, parent, visited, source);
    printTable(distance, parent);
}
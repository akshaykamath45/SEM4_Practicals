#include <stdio.h>
#include <limits.h>
#define vertices 5

void initializeSingleSource(int distance[], int parent[], int source)
{
    for (int i = 0; i < vertices; i++)
    {
        distance[i] = INT_MAX;
        parent[i] = -1;
    }
    distance[source] = 0;
}

void bellmanFord(int graph[][vertices], int distance[], int parent[], int source)
{
    for (int u = 0; u < vertices; u++)
    {
        for (int v = 0; v < vertices; v++)
        {
            if (graph[u][v] != 0 && distance[u] + graph[u][v] < distance[v])
            {
                distance[v] = distance[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
}

void printTable(int distance[], int parent[])
{
    printf("Vertices\tDistance\tParent\t\n");
    for (int i = 0; i < vertices; i++)
    {
        printf("%d\t\t%d\t\t%d\n", i, distance[i], parent[i]);
    }
}
int main()
{
    int graph[vertices][vertices] = {{0, 6, 0, 7, 0},
                                     {0, 0, 5, 8, -4},
                                     {0, -2, 0, 0, 0},
                                     {0, 0, -3, 0, 9},
                                     {2, 0, 7, 0, 0}};
    int distance[vertices];
    int parent[vertices];
    int source = 0;

    initializeSingleSource(distance, parent, source);

    for (int i = 0; i < vertices - 1; i++)
    {
        bellmanFord(graph, distance, parent, source);
    }

    printTable(distance, parent);
}
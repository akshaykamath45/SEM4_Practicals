#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#define vertices 9

int minKey(int key[], bool mst_set[])
{
    int min = INT_MAX;
    int minIndex;

    for (int i = 0; i < vertices; i++)
    {
        if (key[i] < min && mst_set[i] == false)
        {
            min = key[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void printEdges(int key[], int parent[])
{
    printf("Edge\t Weight\n");
    for (int i = 1; i < vertices; i++)
    {
        printf("%d - %d \t %d \n", parent[i], i, key[i]);
    }
}

void prims(int graph[][vertices])
{
    bool mst_set[20];
    int parent[20];
    int key[20];

    for (int i = 0; i < vertices; i++)
    {
        mst_set[i] = false;
        key[i] = INT_MAX;
    }

    parent[0] = -1;
    key[0] = 0;

    for (int i = 0; i < vertices; i++)
    {
        int u = minKey(key, mst_set);
        mst_set[u] = true;
        for (int v = 0; v < vertices; v++)
        {
            if (graph[u][v] && mst_set[v] == false && graph[u][v] < key[v])
            {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }
    printEdges(key, parent);
}

int main()
{
    int graph[][vertices] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                             {4, 0, 8, 0, 0, 0, 0, 11, 0},
                             {0, 8, 0, 7, 0, 4, 0, 0, 2},
                             {0, 0, 7, 0, 9, 14, 0, 0, 0},
                             {0, 0, 0, 9, 0, 10, 0, 0, 0},
                             {0, 0, 4, 14, 10, 0, 2, 0, 0},
                             {0, 0, 0, 0, 0, 2, 0, 1, 6},
                             {8, 11, 0, 0, 0, 0, 1, 0, 7},
                             {0, 0, 2, 0, 0, 0, 6, 7, 0}};
    prims(graph);
}
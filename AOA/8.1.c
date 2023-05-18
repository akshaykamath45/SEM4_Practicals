#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int n_vertices, n_colors, n_edges;
int colors[MAX];
int graph[MAX][MAX];

int isSafe(int vertex, int color)
{
    for (int i = 0; i < n_vertices; i++)
    {
        if (graph[vertex][i] && colors[i] == color)
        {
            return 0;
        }
    }
    return 1;
}

int graphColoring(int vertex)
{
    if (vertex == n_vertices)
    {
        return 1;
    }
    for (int i = 1; i <= n_colors; i++)
    {
        if (isSafe(vertex, i) == 1)
        {
            colors[vertex] = i;
            if (graphColoring(vertex + 1))
            {
                return 1;
            }
            else
            {
                colors[vertex] = 0;
            }
        }
    }
}

int main()
{
    printf("Enter number of vertices : ");
    scanf("%d", &n_vertices);

    printf("Enter number of edges : ");
    scanf("%d", &n_edges);

    printf("Enter number of colors : ");
    scanf("%d", &n_colors);

    for (int i = 0; i < n_vertices; i++)
    {
        colors[i] = 0;
        for (int j = 0; j < n_vertices; j++)
        {
            graph[i][j] = 0;
        }
    }
    for (int i = 0; i < n_edges; i++)
    {
        int u, v;
        printf("Enter edge %d : ", i + 1);
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }

    if (graphColoring(0) == 1)
    {
        printf("Vertex\t Colors\n");
        for (int i = 0; i < n_vertices; i++)
        {
            printf("%d\t %d\n", i, colors[i]);
        }
    }
    else
    {
        printf("Cannot done with %d colors ", n_colors);
    }
    return 0;
}
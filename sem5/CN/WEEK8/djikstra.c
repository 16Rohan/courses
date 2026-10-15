#include <stdio.h>
#include <stdlib.h>
#define INF 999999999

int n, src, dest;
int *visited;
int *distance;
int **matrix;

void djikstras(void)
{
    int *path = malloc(n * sizeof(int));

    if (path == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
        distance[i] = INF;
        path[i] = -1;
    }

    distance[src] = 0;

    for (int count = 0; count < n; count++)
    {
        int cur = -1;
        int mindist = INF;

        // Find the unvisited node with the smallest distance
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && distance[i] < mindist)
            {
                mindist = distance[i];
                cur = i;
            }
        }

        // No reachable unvisited node remains
        if (cur == -1)
            break;

        visited[cur] = 1;

        // Stop when the destination is finalized
        if (cur == dest)
            break;

        // Relax all outgoing edges
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] &&
                matrix[cur][i] != INF &&
                matrix[cur][i] >= 0 &&
                distance[cur] <= INF - matrix[cur][i])
            {

                int newdist = distance[cur] + matrix[cur][i];

                if (newdist < distance[i])
                {
                    distance[i] = newdist;
                    path[i] = cur;
                }
            }
        }
    }

    if (distance[dest] == INF)
    {
        printf("No path exists from %d to %d.\n", src, dest);
        free(path);
        return;
    }

    // Reconstruct the path in reverse
    int *route = malloc(n * sizeof(int));

    if (route == NULL)
    {
        printf("Memory allocation failed.\n");
        free(path);
        return;
    }

    int len = 0;

    for (int v = dest; v != -1; v = path[v])
    {
        route[len++] = v;

        if (v == src)
            break;
    }

    if (route[len - 1] != src)
    {
        printf("No path exists from %d to %d.\n", src, dest);
    }
    else
    {
        printf("Shortest path: ");

        for (int i = len - 1; i >= 0; i--)
        {
            printf("%d", route[i]);

            if (i > 0)
                printf(" -> ");
        }

        printf("\nShortest distance: %d\n", distance[dest]);
    }

    free(route);
    free(path);
}

int main()
{
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // initialization
    visited = malloc(n * sizeof(int));
    distance = malloc(n * sizeof(int));
    matrix = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        matrix[i] = malloc(n * sizeof(int));
        distance[i] = INF;
        visited[i] = 0;
    }

    printf("Enter Adjacency Matrix: ");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Select source node: ");
    scanf("%d", &src);
    printf("Select destination node: ");
    scanf("%d", &dest);

    // error checking for source to be within limit
    // error checking for source and destination to not be equal
    // or a funny error message printing that the shortest distance is 0

    // this is out of my hands, I'm going to make an AI do that.

    djikstras();

    return 0;
}
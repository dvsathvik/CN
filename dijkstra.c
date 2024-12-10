#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define INF 100000
void main()
{
    int n , src , des;
    printf("Enter the number of vertices:\n");
    scanf("%d",&n);
    int graph[n][n],distance[n],prev_hop[n];
    bool completed[n];
    printf("Enter the cost graph:\n");
    for (int i = 0; i < n; i++)
    {
        completed[i] = false;
        distance[n] = INF;
        for (int  j = 0; j < n ; j++)
        {
            scanf("%d",&graph[i][j]);
            if (graph[i][j] == 0)
            {
                graph[i][j] = INF;
            }
            if (i == j)
            {
                graph[i][j] = 0;
            }
        }
    }
    printf("Enter source and destination:\t");
    scanf("%d %d",&src,&des);

    distance[src] = 0;
    prev_hop[src] = -1;

    while (completed[des] == false)
    {
        
        printf("came");
        int min_distance = 0;
        for (int i = 0; i < n; i++)
        {
            if (completed[i] == false && (distance[i] < distance[min_distance] || completed[min_distance] == true))
            {
                min_distance = i;
            }
        }
        completed[min_distance] = true;
        for (int i = 0; i < n; i++)
        {
            if (completed[i] == false && (distance[i] > distance[min_distance]+graph[min_distance][i]))
            {
                distance[i] = distance[min_distance]+graph[min_distance][i];
                prev_hop[i] = min_distance;
            }
        }
    }

    int queue[10],i = 0,cur = -1;

    do
    {
        if (cur == -1){ cur = des;}
        else
        {
            cur = prev_hop[cur];
        }
        queue[i++] = cur;
    } while (cur != src);

    printf("path:\n");
    do
    {
        i--;
        printf("%d\t",queue[i]);
    } while (i != 0);
    printf("Total cost:\t%d",distance[des]);
}
#include<stdio.h>
#define INF 9999
#define MAX 10
int main(){
	int i,j,count,n,u;
	int source;
	printf("enter the number of vertices:");
	scanf("%d",&n);
	int dist[MAX],visited[MAX],cost[MAX][MAX];
	printf("enter the cost adjacent matrix( 9999 for no route)");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&cost[i][j]);
		}
	}
	printf("enter the source node from 0 to %d",n-1);
	scanf("%d",&source);
	for(i=0;i<n;i++){
		dist[i]=cost[source][i];
		visited[i]=0;
	}
	dist[source]=0;
	visited[source]=1;
	for(i=1;i<n;i++){
		int min=INF;
		for(j=0;j<n;j++){
			if(!visited[j]&&dist[j]<min){
				min=dist[j];
				u=j;
			}
		}
		visited[u]=1;
	}
	for(i=0;i<n;i++){
		if(!visited[i]&&cost[u][i]!=INF&&cost[u][i]+dist[u]<dist[i]){
			dist[i]=cost[u][i]+dist[u];
		}
	}
	printf("Shortest distances from node %d:\n", source);
    for (i = 0; i < n; i++) {
        if (dist[i] == INF) {
            printf("To node %d: Infinity\n", i);
        } else {
            printf("To node %d: %d\n", i, dist[i]);
        }
    }

    return 0;
	
}
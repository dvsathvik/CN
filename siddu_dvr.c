#include<stdio.h>//getting next hop wrong
#define INF 9999
#define MAX 10
int main(){
	int updated,n,i,j,k;
	int cost[MAX][MAX],routingtable[MAX][MAX],distance[MAX][MAX];
	printf("enter the number of nodes:");
	scanf("%d",&n);
	printf("enter the cost adjacency matrix(0 for no direct connection):\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&cost[i][j]);

			if(i==j){
				cost[i][j]=0;
			}else if(cost[i][j]==0){
				cost[i][j]=INF;
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			distance[i][j]=cost[i][j];
			if(cost[i][j]!=INF&&i!=j){
				routingtable[i][j]=j;
			}else{
				routingtable[i][j]=-1;
			}

		}
	}
	do{
		updated=0;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
			  if(i!=j){
				for(k=0;k<n;k++){
					if(distance[i][j]>distance[i][k]+cost[k][j]){
						distance[i][j]=distance[i][k]+cost[k][j];
						routingtable[i][j]=routingtable[i][k];
						updated=1;
				     	}
					}

				}
			}
		}

	}while(updated);
	for(i=0;i<n;i++){
		printf("\nRouting table for node %d:\n",i);
		printf("Destination\tnexthop\tcost\n");
		for(j=0;j<n;j++){
			if(routingtable[i][j]==-1){
				printf("%d\t\t-\t\t%d\n",j,distance[i][j]);
			}else{
				printf("%d\t\t%d\t\t%d\n",j,routingtable[i][j],distance[i][j]);
			}
		}
	}
	return 0;

}
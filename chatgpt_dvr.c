#include <stdio.h>
#define INF 9999
#define MAX 10

void displayRoutingTable(int distance[MAX][MAX], int next[MAX][MAX], int nodes, int step) {
    printf("\nRouting Tables After Step %d:\n", step);
    for (int i = 0; i < nodes; i++) {
        printf("Routing table for Node %d:\n", i);
        printf("Destination   Distance   Next Hop\n");
        for (int j = 0; j < nodes; j++) {
            if (distance[i][j] == INF)
                printf("%11d   %8s   %8s\n", j, "INF", "-");
            else
                printf("%11d   %8d   %8d\n", j, distance[i][j], next[i][j]);
        }
        printf("\n");
    }
}

void dvr(int cost[MAX][MAX], int nodes) {
    int distance[MAX][MAX], next[MAX][MAX];
    int i, j, k, step = 0;

    // Initialize the distance and next matrices
    for (i = 0; i < nodes; i++) {
        for (j = 0; j < nodes; j++) {
            distance[i][j] = cost[i][j];
            next[i][j] = (cost[i][j] == INF || i == j) ? -1 : j; // Set -1 for no next hop
        }
    }

    printf("\nInitial Routing Tables:\n");
    displayRoutingTable(distance, next, nodes, step);

    // DVR Algorithm: Updating distance matrix
    for (k = 0; k < nodes; k++) { // Intermediate nodes
        for (i = 0; i < nodes; i++) { // Source nodes
            for (j = 0; j < nodes; j++) { // Destination nodes
                if (distance[i][k] + distance[k][j] < distance[i][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                    next[i][j] = next[i][k]; // Update next hop
                }
            }
        }
        step++;
        displayRoutingTable(distance, next, nodes, step); // Display routing table after each hop
    }

    printf("\nFinal Routing Tables:\n");
    displayRoutingTable(distance, next, nodes, step);
}

int main() {
    int cost[MAX][MAX];
    int nodes, i, j;

    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);

    printf("Enter the cost adjacency matrix (enter %d for infinity):\n", INF);
    for (i = 0; i < nodes; i++) {
        for (j = 0; j < nodes; j++) {
            scanf("%d", &cost[i][j]);
            if (i == j) cost[i][j] = 0; // Cost to itself is always 0
        }
    }

    dvr(cost, nodes);

    return 0;
}

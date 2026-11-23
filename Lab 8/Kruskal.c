#include <stdio.h>

int parent[10];

int find(int x) {
    while (parent[x] != x)
        x = parent[x];

    return x;
}

int main() {
    int n, e;
    int source[20], destination[20], weight[20];
    int i, j, temp;
    int total = 0, count = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter source, destination and weight:\n");

    for (i = 0; i < e; i++) {
        scanf("%d %d %d",
              &source[i],
              &destination[i],
              &weight[i]);
    }

    // Sort edges by weight
    for (i = 0; i < e - 1; i++) {
        for (j = i + 1; j < e; j++) {
            if (weight[i] > weight[j]) {
                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;

                temp = source[i];
                source[i] = source[j];
                source[j] = temp;

                temp = destination[i];
                destination[i] = destination[j];
                destination[j] = temp;
            }
        }
    }

    // Initially, every vertex is separate
    for (i = 1; i <= n; i++)
        parent[i] = i;

    printf("\nMinimum Spanning Tree:\n");

    for (i = 0; i < e; i++) {
        int a = find(source[i]);
        int b = find(destination[i]);

        if (a != b) {
            printf("%d - %d = %d\n",
                   source[i],
                   destination[i],
                   weight[i]);

            total = total + weight[i];
            parent[a] = b;
            count++;
        }

        if (count == n - 1)
            break;
    }

    printf("Minimum cost = %d\n", total);

    return 0;
}
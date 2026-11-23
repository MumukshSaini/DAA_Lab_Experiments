#include <stdio.h>

typedef struct {
    int weight;
    int profit;
} Item;

Item item[20];
int n, capacity;
int maxProfit = 0;

void sortItems() {
    int i, j;
    Item temp;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if ((float)item[i].profit / item[i].weight <
                (float)item[j].profit / item[j].weight) {
                
                temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }
}

float bound(int level, int weight, int profit) {
    float result = profit;
    int i = level;
    int remaining;

    if (weight >= capacity)
        return 0;

    while (i < n && weight + item[i].weight <= capacity) {
        weight += item[i].weight;
        result += item[i].profit;
        i++;
    }

    if (i < n) {
        remaining = capacity - weight;
        result += remaining *
                  ((float)item[i].profit / item[i].weight);
    }

    return result;
}

void knapsack(int level, int weight, int profit) {
    if (weight <= capacity && profit > maxProfit)
        maxProfit = profit;

    if (level == n)
        return;

    if (bound(level + 1,
              weight + item[level].weight,
              profit + item[level].profit) > maxProfit) {
        knapsack(level + 1,
                 weight + item[level].weight,
                 profit + item[level].profit);
    }

    if (bound(level + 1, weight, profit) > maxProfit) {
        knapsack(level + 1, weight, profit);
    }
}

int main() {
    int i;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weight and profit of each item:\n");
    for (i = 0; i < n; i++)
        scanf("%d %d", &item[i].weight, &item[i].profit);

    printf("Enter capacity: ");
    scanf("%d", &capacity);

    sortItems();
    knapsack(0, 0, 0);

    printf("Maximum profit = %d\n", maxProfit);

    return 0;
}
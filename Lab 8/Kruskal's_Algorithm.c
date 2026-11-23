
#include <stdio.h>

int main()
{
    int u[] = {0, 0, 0, 1, 1, 2};
    int v[] = {1, 2, 3, 2, 3, 3};
    int w[] = {10, 6, 5, 0, 15, 4};

    int parent[] = {0, 1, 2, 3};
    int i, j, temp, total = 0, count = 0;

    for(i = 0; i < 6; i++)
    {
        for(j = i+1; j < 6; j++)
        {
            if(w[i] > w[j])
            {
                temp = w[i]; w[i] = w[j]; w[j] = temp;
                temp = u[i]; u[i] = u[j]; u[j] = temp;
                temp = v[i]; v[i] = v[j]; v[j] = temp;
            }
        }
    }

    printf("Edges in MST:\n");

    for(i = 0; i < 6; i++)
    {
        if(parent[u[i]] != parent[v[i]])
        {
            printf("%d - %d = %d\n", u[i], v[i], w[i]);

            total += w[i];
            parent[u[i]] = parent[v[i]];
            count++;

            if(count == 3)
                break;
        }
    }

    printf("Total cost = %d", total);

    return 0;
}

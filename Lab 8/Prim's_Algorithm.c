#include <stdio.h>

int main()
{
    int a[4][4] = {
        {0, 10, 6, 5},
        {10, 0, 0, 15},
        {6, 0, 0, 4},
        {5, 15, 4, 0}
    };

    int visit[4] = {1, 0, 0, 0};
    int i, j, min, x, y, total = 0;

    printf("Edges in MST:\n");

    for(i = 0; i < 3; i++)
    {
        min = 999;

        for(j = 0; j < 4; j++)
        {
            if(visit[j])
            {
                for(int k = 0; k < 4; k++)
                {
                    if(!visit[k] && a[j][k] != 0 && a[j][k] < min)
                    {
                        min = a[j][k];
                        x = j;
                        y = k;
                    }
                }
            }
        }

        printf("%d - %d = %d\n", x, y, min);

        total += min;
        visit[y] = 1;
    }

    printf("Total cost = %d", total);

    return 0;
}

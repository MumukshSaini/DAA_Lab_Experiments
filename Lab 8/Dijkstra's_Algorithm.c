#include <stdio.h>

int main()
{
    int a[4][4] = {
        {0, 4, 1, 0},
        {4, 0, 2, 5},
        {1, 2, 0, 8},
        {0, 5, 8, 0}
    };

    int d[4] = {0, 999, 999, 999};
    int visit[4] = {0};
    int i, j, min, v;

    for(i = 0; i < 4; i++)
    {
        min = 999;

        for(j = 0; j < 4; j++)
        {
            if(!visit[j] && d[j] < min)
            {
                min = d[j];
                v = j;
            }
        }

        visit[v] = 1;

        for(j = 0; j < 4; j++)
        {
            if(a[v][j] != 0 && !visit[j])
            {
                if(d[v] + a[v][j] < d[j])
                    d[j] = d[v] + a[v][j];
            }
        }
    }

    for(i = 0; i < 4; i++)
        printf("Distance to %d = %d\n", i, d[i]);

    return 0;
}

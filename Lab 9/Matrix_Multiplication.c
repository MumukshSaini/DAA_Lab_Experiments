#include <stdio.h>

int main()
{
    int p[] = {10, 20, 30, 40};
    int dp[5][5] = {0};

    int n = 3;
    int i, j, k, l, min, cost;

    for(l = 2; l <= n; l++)
    {
        for(i = 1; i <= n-l+1; i++)
        {
            j = i+l-1;
            min = 999999;

            for(k = i; k < j; k++)
            {
                cost = dp[i][k] + dp[k+1][j]
                     + p[i-1]*p[k]*p[j];

                if(cost < min)
                    min = cost;
            }

            dp[i][j] = min;
        }
    }

    printf("Minimum Multiplication = %d", dp[1][n]);

    return 0;
}

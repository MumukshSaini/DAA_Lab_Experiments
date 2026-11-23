#include <stdio.h>
#include <string.h>

int main()
{
    char a[] = "ABC";
    char b[] = "AC";

    int m = strlen(a);
    int n = strlen(b);
    int dp[10][10] = {0};

    int i, j;

    for(i = 1; i <= m; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
            {
                if(dp[i-1][j] > dp[i][j-1])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
    }

    printf("LCS Length = %d", dp[m][n]);

    return 0;
}

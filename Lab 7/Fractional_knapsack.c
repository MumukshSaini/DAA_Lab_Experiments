#include <stdio.h>

int main()
{
    int w[] = {10, 20, 30};
    int p[] = {60, 100, 120};
    int n = 3, capacity = 50;
    int i, j, temp;
    float profit = 0;

    for(i = 0; i < n; i++)
    {
        for(j = i+1; j < n; j++)
        {
            if((float)p[i]/w[i] < (float)p[j]/w[j])
            {
                temp = w[i];
                w[i] = w[j];
                w[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    for(i = 0; i < n; i++)
    {
        if(w[i] <= capacity)
        {
            profit += p[i];
            capacity -= w[i];
        }
        else
        {
            profit += (float)p[i]/w[i] * capacity;
            break;
        }
    }

    printf("Maximum Profit = %.2f", profit);

    return 0;
}

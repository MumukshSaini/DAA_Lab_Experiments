#include <stdio.h>

int main()
{
    int s[] = {1, 3, 0, 5, 8, 5};
    int f[] = {2, 4, 6, 7, 9, 9};

    int n = 6, i, j;

    printf("Selected activities: ");

    printf("A1 ");
    j = 0;

    for(i = 1; i < n; i++)
    {
        if(s[i] >= f[j])
        {
            printf("A%d ", i + 1);
            j = i;
        }
    }

    return 0;
}

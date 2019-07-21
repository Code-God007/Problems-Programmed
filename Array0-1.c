#include <stdio.h>

int main()
{
    int n, i, j, r = 0, c = 0, k;
    scanf("%d", &n);
    int a[n][n];
    printf("Enter Elements : \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == 0 && a[i][j] == 0)
            {
                r = 1;
            }
            if (j == 0 && a[i][j] == 0)
            {
                c = 1;
            }
            if (a[i][j] == 0)
            {
                a[0][j] = 0;
                a[i][0] = 0;
            }
        }
    }
    for (i = 1; i < n; i++)
    {
        for (j = 1; j < n; j++)
        {
            if (a[0][j] == 0 || a[i][0] == 0)
            {
                a[i][j] = 0;
            }
        }
    }
    if (r == 1)
    {
        for (i = 0; i < n; i++)
        {
            a[0][i] = 0;
        }
    }
    if (c == 1)
    {
        for (i = 0; i < n; i++)
        {
            a[i][0] = 0;
        }
    }
    printf("After replacing 1's with 0's:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}

#include <stdio.h>

int main()
{
    int n, i, j, temp;
    printf("Enter Size of n x n matrix : ");
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
    printf("Array Before Rotating 90deg\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < n / 2; i++)
    {
        for (j = i; j < n - 1 - i; j++)
        {
            temp = a[i][j];
            a[i][j] = a[n - 1 - j][i];
            a[n - 1 - j][i] = a[n - 1 - i][n - 1 - j];
            a[n - 1 - i][n - 1 - j] = a[j][n - 1 - i];
            a[j][n - 1 - i] = temp;
        }
    }
    printf("Array After Rotating 90deg\n");
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

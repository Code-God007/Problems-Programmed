#include <stdio.h>

int main()
{
    int n, i, j, k, temp, t;
    printf("Enter Size of Arrray : ");
    scanf("%d", &n);
    int a[n];
    printf("Enter Elements : \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter number of rotations you want to perform : ");
    scanf("%d", &k);
    k = k % n;
    for (i = 0; i < k; i++)
    {
        temp = a[n - 1];
        for (j = n - 1; j > 0; j--)
        {
            a[j] = a[j - 1];
        }
        a[0] = temp;
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
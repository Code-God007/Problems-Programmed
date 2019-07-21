#include <stdio.h>
int main()
{
    int n, i, j, temp, k;
    printf("Enter the Size of array : ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the size of group in which you want to reverse : ");
    scanf("%d", &k);
    printf("Enter elements\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i += k)
    {
        if ((i + k) <= n)
        {
            for (int j = 0; j < k / 2; j++)
            {
                temp = a[i + j];
                a[i + j] = a[i + k - 1 - j];
                a[i + k - 1 - j] = temp;
            }
        }
        else if (i < n - 1)
        {
            temp = a[i];
            a[i] = a[n - 1];
            a[n - 1] = temp;
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
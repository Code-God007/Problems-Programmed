#include <stdio.h>
#include <stdlib.h>
int main()
{
    int m, n, i, j, k = 0;
    scanf("%d %d", &m, &n);
    int A[m], B[n];
    int Res[100];
    for (i = 0; i < m; i++)
    {
        scanf("%d", &A[i]);
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &B[i]);
    }
    i = 0, j = 0;
    while (i < m && j < n)
    {
        if (A[i] < B[j])
        {
            i++;
        }
        if (A[i] > B[j])
        {
            j++;
        }
        if (A[i] == B[j])
        {
            Res[k] = A[i];
            k++;
            i++;
            j++;
        }
    }
    for (i = 0; i < k; i++)
    {
        printf("%d ", Res[i]);
    }
}
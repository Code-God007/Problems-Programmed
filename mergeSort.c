#include <stdio.h>

void Merge(int *L, int *R, int *A, int m, int n, int o)
{
    int i, j, k;
    i = j = k = 0;
    while (i < m && j < n)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < m)
    {
        A[k] = L[i];
        i++;
        k++;
    }
    while (j < n)
    {
        A[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int *A, int n)
{
    if (n < 2)
    {
        return;
    }
    int mid = n / 2;
    int left[mid];
    int right[n - mid];
    for (int i = 0; i < mid; i++)
    {
        left[i] = A[i];
    }
    for (int i = mid; i < n; i++)
    {
        right[i - mid] = A[i];
    }
    MergeSort(left, mid);
    MergeSort(right, n - mid);
    Merge(left, right, A, mid, n - mid, n);
}

int main()
{
    int n;
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    MergeSort(A, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
}
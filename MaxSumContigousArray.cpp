#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    int n, i, j, max1 = 0, max2 = 0;
    printf("Enter Size : ");
    scanf("%d", &n);
    int a[n];
    vector<int> v;
    printf("Enter Elements : \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        max2 = max2 + a[i];
        if (max2 < 0)
        {
            max2 = 0;
        }
        if (max1 < max2)
        {
            max1 = max2;
        }
    }
    printf("The Maximum Sum Contigous Array is : %d", max1);
}
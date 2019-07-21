#include <iostream>
using namespace std;
int main()
{
    int i, n, index;
    int l[3] = {2, 1, 3};
    int r[3] = {5, 3, 9};
    n = r[0];
    for (i = 0; i < 3; i++)
    {
        if (n < r[i])
        {
            n = r[i];
        }
    }
    int size = n + 1;
    int a[size] = {0};
    for (i = 0; i < 3; i++)
    {
        a[l[i]] += 1;
        a[r[i] + 1] -= 1;
    }
    int sum = a[0];
    for (i = 0; i < size; i++)
    {
        a[i] += a[i - 1];
        if (sum < a[i])
        {
            sum = a[i];
            index = i;
        }
    }
    printf("Maximum Occured element is %d", index);
}
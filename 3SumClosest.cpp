#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{
    int n, target;
    cin >> n;
    int a[n];
    int closestSum = INT32_MAX;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter Target: ";
    cin >> target;
    sort(a, a + n);
    for (int i = 0; i < n - 2; i++)
    {
        int j = i + 1, k = n - 1;
        while (j < k)
        {
            int sum = a[i] + a[j] + a[k];
            if (abs(target - sum) < abs(target - closestSum))
            {
                closestSum = sum;
            }
            else if (sum < target)
            {
                j++;
            }
            else if (sum > target)
            {
                k--;
            }
        }
    }
    cout << "The Closest Sum is: " << closestSum;
}
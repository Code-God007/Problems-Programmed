#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
vector<int> func(vector<int> arr, int M)
{
    int maximum = M, S = arr.size(), left = 0, right = 0, l, r, max = -1;
    while (right < S)
    {
        if (arr[right] == 1)
        {
            right++;
        }
        else if (arr[right] == 0 && M)
        {
            right++;
            M--;
        }
        else if (arr[right] == 0)
        {
            while (arr[left] != 0)
            {
                left++;
            }
            left++;
            if (M < maximum)
            {
                M++;
            }
            if (left > right)
            {
                right = left;
            }
            if (right - left > max)
            {
                max = right - left;
            }
            l = left;
            r = right;
        }
    }
}
int main()
{
}
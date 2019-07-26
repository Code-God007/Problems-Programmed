#include <iostream>
#include <utility>
#include <algorithm>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
bool second(pair<int, int> &a, pair<int, int> &b)
{
    return (a.second < b.second);
}

int main()
{
    int n, min, max;
    cout << "Enter Size of array : ";
    cin >> n;
    int a[n], I[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        I[i] = i;
    }
    vector<pair<int, int>> vect;
    for (int i = 0; i < n; i++)
    {
        vect.push_back(make_pair(I[i], a[i]));
    }
    for (int i = 0; i < n; i++)
    {
        cout << vect[i].first << " " << vect[i].second << endl;
    }
    sort(vect.begin(), vect.end(), second);
    cout << "After Sorting : \n";
    for (int i = 0; i < n; i++)
    {
        cout << vect[i].first << " " << vect[i].second << endl;
    }
    min = vect[0].first;
    max = 0;
    for (int i = 0; i < n; i++)
    {
        if (vect[i].first - min > max)
        {
            max = vect[i].first - min;
        }
        if (vect[i].first < min)
        {
            min = vect[i].first;
        }
    }
    cout << max;
}
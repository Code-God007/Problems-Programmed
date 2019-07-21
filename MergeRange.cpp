#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, b;
    cout << "Enter no of values";
    cin >> n;
    vector<pair<int, int>> vect, vect1;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        vect.push_back(make_pair(a, b));
    }
    sort(vect.begin(), vect.end());
    for (int i = 1; i < n; i += 2)
    {
        if ((vect[i].first < vect[i - 1].second) && (vect[i].second > vect[i - 1].second))
        {
            vect[i - 1].second = vect[i].second;
            vect1.push_back(vect[i - 1]);
        }
        else
        {
            vect1.push_back(vect[i - 1]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << vect1[i].first << " ";
        cout << vect1[i].second << endl;
    }
    return 0;
}

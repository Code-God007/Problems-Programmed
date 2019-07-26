#include <iostream>
#include <vector>

using namespace std;

vector<int> maxone(vector<int> &a, int B)
{
    vector<int> v;
    int mr = 0, ml = 0;
    int l = 0, r = 0, max = 0, count = 0;
    while (r < a.size())
    {
        if (a[r] == 0 && count < B)
        {
            count++;
            r++;
        }
        else if (a[r] == 0 && count >= B)
        {
            while (a[l] != 0)
            {
                l++;
            }
            l++;
            count--;
        }
        else if (a[r] == 1)
        {
            r++;
        }
        if (r - l > max)
        {
            mr = r;
            ml = l;
            max = r - l;
        }
    }
    for (int i = ml; i < mr; i++)
    {
        v.push_back(i);
    }
    return v;
}

int main()
{
    vector<int> v, sol;
    int n, FLIPS, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        v.push_back(m);
    }
    cout << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "Enter No of Flips allowed: ";
    cin >> FLIPS;
    sol = maxone(v, FLIPS);
    cout << endl;
    for (int i = 0; i < sol.size(); i++)
    {
        cout << sol[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}
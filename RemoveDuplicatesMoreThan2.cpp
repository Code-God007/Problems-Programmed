#include <iostream>
using namespace std;

int removeDup(int *a, int n)
{
    int j = 0;
    for (int i = 1; i < n; i++)
    {
        if (i < n - 2 && a[i] == a[i + 1] && a[i + 1] == a[i + 2])
        {
            continue;
        }
        else
        {
            a[j++] = a[i];
        }
    }
    return j;
}

int main()
{
    int n, res;
    cout << "Enter Size of Array: ";
    cin >> n;
    int a[n];
    cout << "Enter Elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    res = removeDup(a, n);
    for (int i = 0; i < res; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}

#include <iostream>
using namespace std;

int main()
{
    int j = 0, i = 1, n;
    cout << "Enter Size of Array: ";
    cin >> n;
    int a[n];
    cout << "Enter Elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[j])
        {
            j++;
            a[j] = a[i];
        }
    }
    for (int i = 0; i < j + 1; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
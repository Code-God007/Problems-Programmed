#include <iostream>
using namespace std;

int main()
{
    int n, x, y, u, v;
    cout << "Enter size of n x n Array : ";
    cin >> n;
    int a[n][n] = {0};
    int b[n][n] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    x = 0;
    y = n - 1;
    u = n - 1;
    v = 0;
    while (x <= u && y >= v)
    {
        for (int i = v; i <= y; i++)
        {
            cout << a[x][i] << " ";
        }
        x++;
        for (int j = x; j <= u; j++)
        {
            cout << a[j][y] << " ";
        }
        y--;
        for (int k = y; k >= v; k--)
        {
            cout << a[u][k] << " ";
        }
        u--;
        for (int z = u; z >= x; z--)
        {
            cout << a[z][v] << " ";
        }
        v++;
    }
    cout << endl;
}
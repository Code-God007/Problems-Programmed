#include <iostream>
#include <tuple>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    int M, N, O;
    int Min, Max, minimum = 100000, Min_diff;
    cin >> M >> N >> O;
    int A[M], B[N], C[O];
    vector<int> res;
    for (int i = 0; i < M; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
    }
    for (int i = 0; i < O; i++)
    {
        cin >> C[i];
    }

    int i = 0, j = 0, k = 0, l = 0;
    while (i < M && j < N && k < O)
    {
        Min = min(min(A[i], B[j]), C[k]);
        Max = max(max(A[i], B[j]), C[k]);
        Min_diff = Max - Min;
        if (Min_diff < minimum)
        {
            minimum = Min_diff;
            res.push_back(A[i]);
            res.push_back(B[j]);
            res.push_back(C[k]);
        }
        if (A[i] == Min)
        {
            i++;
        }
        else if (B[j] == Min)
        {
            j++;
        }
        else if (C[k] == Min)
        {
            k++;
        }
    }
    cout << "Absolute Minimum difference is : " << minimum << " \n"
         << res[res.size() - 3] << " " << res[res.size() - 2] << " " << res[res.size() - 1];
}
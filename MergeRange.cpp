#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Interval
{
    int start, end;
};

bool compare(Interval i1, Interval i2)
{
    return (i1.start < i2.start);
}

int main()
{
    int n, a, b;
    cout << "Enter no of values: ";
    cin >> n;
    Interval arr[n];
    cout << "Enter Values: \n";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].start >> arr[i].end;
    }

    sort(arr, arr + n, compare);

    stack<Interval> st;
    st.push(arr[0]);
    for (int i = 1; i < n; i++)
    {
        Interval top = st.top();
        if (top.end < arr[i].start)
        {
            st.push(arr[i]);
        }
        else if (top.end < arr[i].end)
        {
            top.end = arr[i].end;
            st.pop();
            st.push(top);
        }
    }

    while (!st.empty())
    {
        Interval t = st.top();
        cout << t.start << " " << t.end << endl;
        st.pop();
    }
    return 0;
}

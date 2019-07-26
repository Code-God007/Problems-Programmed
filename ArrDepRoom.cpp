#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Interval
{
    int ar, dep;
};

bool compare(Interval i1, Interval i2)
{
    return (i1.ar < i2.ar);
}

bool checkRoom(Interval *arr, int n, int k)
{
    int room_needed = 1, result = 1;
    int i = 1, j = 0;
    while (i < n && j < n)
    {
        if (arr[i].ar < arr[j].dep)
        {
            room_needed++;
            i++;
            if (room_needed > result)
            {
                result = room_needed;
            }
        }
        else
        {
            room_needed--;
            j++;
        }
    }
    if (result > k)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    int n, cur, k;
    bool avial;
    cout << "Enter no of customers: ";
    cin >> n;
    Interval arr[n];
    cout << "Enter the Arrival and Departure dates as space seperated integers:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].ar >> arr[i].dep;
    }
    cout << "Enter the number of rooms: ";
    cin >> k;
    sort(arr, arr + n, compare);
    avial = checkRoom(arr, n, k);
    if (avial)
    {
        cout << "Yes, Room Availiable";
    }
    else
    {
        cout << "Sorry, Room's are Full";
    }
}
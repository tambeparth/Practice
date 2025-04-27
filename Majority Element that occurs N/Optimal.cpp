#include <bits/stdc++.h>
using namespace std;
int majorityElement(vector<int> &arr)
{
    int n = arr.size();
    int cnt = 0;
    int elem = 0;
    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
        {
            cnt = 1;
            elem = arr[i];
        }
        else if (elem == arr[i])
            cnt++;
        else
        {
            cnt--;
        }
    }

    // checking selected elen is majority or not
    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (elem == arr[i])
        {
            cnt++;
        }
    }
    if (cnt > n / 2)
    {
        return elem;
    }
    return -1;
}

int main()
{
    vector<int> arr = {2, 3, 3, 2, 2, 3, 2};
    cout << majorityElement(arr);
    return 0;
}
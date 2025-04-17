#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int numofInversion(vector<int> &arr, int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (arr[i] > arr[j] && i < j)
            {
                cnt++;
            }
        }
    }
    return cnt;
}
int main()
{
    vector<int> arr = {5, 4, 6, 7, 8};
    int n = 5;
    int cnt = numofInversion(arr, n);
    cout << "The number of inversion is:" << cnt << endl;
    return 0;
}
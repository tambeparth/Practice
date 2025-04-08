#include <bits/stdc++.h>
using namespace std;
int findDuplicate(vector<int> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            return arr[i];
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {1, 3, 2, 5, 1};
    cout << " Duplicate element is:" << findDuplicate(arr) << endl;
    return 0;
}
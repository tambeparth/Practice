#include <bits/stdc++.h>
using namespace std;
int majorityElement(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == arr[i])
            {
                count++;
            }
        }

        if (count > n / 2)
        {
            return arr[i];
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {3, 1, 3, 3, 2, 3, 4};
    cout << majorityElement(arr);
    return 0;
}
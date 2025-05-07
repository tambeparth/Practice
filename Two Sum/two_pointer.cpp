#include <bits/stdc++.h>
using namespace std;

string twoSum(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int left = 0;
    int right = n - 1;
    while (left < right)
    {
        int sum = arr[left] + arr[right];

        if (target == sum)
        {
            return "YES";
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return "NO";
}

int main()
{
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 19;
    string ans = twoSum(arr, target);
    cout << ans;
    return 0;
}

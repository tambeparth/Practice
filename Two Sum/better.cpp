#include <bits/stdc++.h>
#include <string>
using namespace std;

string twoSum(vector<int> &arr, int target)
{

    int n = arr.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        int ans = target - num;
        if (mp.find(ans) != mp.end())
        {
            return "Yes";
        }
        mp[num] = i;
    }
    return "NO";
}
int main()
{
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    string ans = twoSum(arr, target);
    cout << "This is the answer for variant 1: " << ans << endl;
    return 0;
}
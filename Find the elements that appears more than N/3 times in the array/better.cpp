#include <bits/stdc++.h>
using namespace std;
vector<int> majorityElement(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ls;
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    for (auto &pair : freq)
    {
        if (pair.second > n / 3)
        {
            ls.push_back(pair.first);
        }
        if (ls.size() == 2)
            break;
    }
    return ls;
}

int main()
{
    vector<int> arr = {11, 33, 33, 11, 33, 11};
    vector<int> ans = majorityElement(arr);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}
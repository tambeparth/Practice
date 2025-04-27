#include <bits/stdc++.h>
using namespace std;
vector<int> majorityElement(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ls;

    for (int i = 0; i < n; i++)
    {
        if (ls.size() == 0 || ls[0] != arr[i])
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (arr[i] == arr[j])
                {
                    cnt++;
                }
            }
            if (cnt > n / 3)
            {
                ls.push_back(arr[i]);
            }
        }
        if (ls.size() == 2)
        {
            break;
        }
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

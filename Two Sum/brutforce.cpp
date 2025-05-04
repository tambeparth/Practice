
#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &arr, int target)
{
    vector<int> ans;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return {-1, -1};
}
// bool twoSum(vector<int> &arr, int tar)
// {
//     int n = arr.size();
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (arr[i] + arr[j] == tar)
//             {
//                 return true;
//             }
//         }
//     }
//     return false;
// }

int main()
{
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 16;
    vector<int> ans = twoSum(arr, target);

    if (ans[0] == -1)
    {
        cout << "No valid pair found." << endl;
    }
    else
    {
        cout << "Pair is: {" << arr[ans[0]] << ", " << arr[ans[1]] << "}" << endl;
    }

    return 0;
}
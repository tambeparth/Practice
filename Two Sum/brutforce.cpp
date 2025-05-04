#include <iostream>
#include <vector>
using namespace std;
bool twoSum(vector<int> &arr, int tar)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == tar)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<int> arr = {2, 6, 5, 8, 11};
    int tar = 15;
    bool ans = twoSum(arr, tar);
    cout << boolalpha << ans;
    return 0;
}
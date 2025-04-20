#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool binarySearch(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
            return true;
        else if (target > nums[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
}
bool searchMat(vector<vector<int>> &mat, int target)
{
    int n = mat.size();
    int m = mat[0].size();
    for (int i = 0; i < n; i++)
    {
        if (mat[i][0] <= target && target <= mat[i][m - 1])
        {
            return binarySearch(mat[i], target);
        }
    }
    return false;
}
int main()
{
    vector<vector<int>> mat = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    searchMat(mat, 8) == true ? cout << "true\n" : cout << "false\n";
}
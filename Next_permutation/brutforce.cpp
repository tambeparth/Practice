#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void findPermutations(vector<int> &nums, vector<vector<int>> &perms)
{
    sort(nums.begin(), nums.end());
    do
    {
        perms.push_back(nums);
    } while (next_permutation(nums.begin(), nums.end()));
}

int findIndex(vector<vector<int>> &perms, vector<int> &nums)
{
    for (int i = 0; i < perms.size(); i++)
    {
        if (perms[i] == nums)
        {
            return i;
        }
    }
    return -1;
}

void nextPermutation(vector<int> &nums)
{
    vector<vector<int>> perms;
    findPermutations(nums, perms);
    int index = findIndex(perms, nums);
    if (index == perms.size() - 1)
    {
        nums = perms[0];
    }
    else
    {
        nums = perms[index + 1];
    }
}

int main()
{
    vector<int> nums = {1, 2, 3};
    nextPermutation(nums);
    cout << "Next Permutation:";
    for (auto num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
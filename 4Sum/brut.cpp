#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = nums.size();
    set<vector<int>> uniqueQuadruplets;

    // Try all possible combinations of 4 numbers
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    // Use long long to prevent overflow
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                    if (sum == target)
                    {
                        // Store the 4 numbers in a sorted way
                        vector<int> quad = {nums[i], nums[j], nums[k], nums[l]};
                        sort(quad.begin(), quad.end());

                        // Insert into set to avoid duplicates
                        uniqueQuadruplets.insert(quad);
                    }
                }
            }
        }
    }

    // Convert set to vector for final result
    vector<vector<int>> result(uniqueQuadruplets.begin(), uniqueQuadruplets.end());
    return result;
}

int main()
{
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;

    vector<vector<int>> ans = fourSum(nums, target);

    cout << "The quadruplets are:\n";
    for (const auto &quad : ans)
    {
        cout << "[ ";
        for (int num : quad)
        {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}

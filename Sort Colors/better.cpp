#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int count_0 = 0;
        int count_1 = 0;
        int count_2 = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                count_0++;
            }
            else if (nums[i] == 1)
            {
                count_1++;
            }
            else
            {
                count_2++;
            }
        }

        int i = 0;

        while (count_0--)
            nums[i++] = 0;
        while (count_1--)
            nums[i++] = 1;
        while (count_2--)
            nums[i++] = 2;
    }
};

int main()
{
    vector<int> nums = {0, 1, 2, 1, 0, 2};
    Solution sol;
    sol.sortColors(nums);

    for (auto num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
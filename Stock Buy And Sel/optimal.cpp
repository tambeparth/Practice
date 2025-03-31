// time complexity = O(n) ans s.c = O(1)

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int maxVal = 0;
        int minVal = INT8_MAX;

        if (n == 0)
            return 0;

        for (int i = 0; i < n; i++)
        {
            minVal = min(minVal, prices[i]);
            maxVal = max(maxVal, prices[i] - minVal);
        }
        return maxVal;
    }
};

int main()
{
    vector<int> prices = {7, 6, 4, 3, 1};
    Solution sol;
    int max = sol.maxProfit(prices);
    cout << "Max Price: " << max << endl;
    return 0;
}
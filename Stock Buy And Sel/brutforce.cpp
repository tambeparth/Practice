// time complexity = O(n) ans s.c = O(1)

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxPrice(vector<int> &prices)
    {
        int n = prices.size();
        int profit = 0;
        if (n == 0)
            return 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (prices[j] > prices[i])
                {
                    profit = max((prices[j] - prices[i]), profit);
                }
            }
        }
        return profit;
    }
};

int main()
{
    vector<int> prices = {7, 6, 4, 3, 1};
    Solution sol;
    int max = sol.maxPrice(prices);
    cout << "MAX PROFIT: " << max << endl;
    return 0;
}
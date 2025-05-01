
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countPath(int i, int j, int m, int n, vector<vector<int>> &dp)
    {
        if (i >= m || j >= n)
            return 0;
        if (i == m - 1 && j == n - 1)
            return 1;
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        else
        {
            return dp[i][j] = countPath(i, j + 1, m, n, dp) + countPath(i + 1, j, m, n, dp);
        }
    }

    int uniPath(int m, int n)
    {
        vector<vector<int>> dp(m + 1, (vector<int>(n + 1, -1)));
        int num = countPath(0, 0, m, n, dp); // Call Recursive Function
        if (m == 1 || n == 1)
        {
            return num;
        }
        return dp[0][0];
    }
};

int main()
{
    Solution obj;
    int ans = obj.uniPath(3, 3);
    cout << "Total No. Path Count: " << ans << endl;
    return 0;
}
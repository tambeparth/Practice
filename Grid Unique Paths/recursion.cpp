
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countPath(int i, int j, int m, int n)
    {
        if (i >= m || j >= n)
        {
            return 0;
        }
        if (i == m - 1 && j == n - 1)
        {
            return 1;
        }
        else
        {
            return countPath(i + 1, j, m, n) + countPath(i, j + 1, m, n); // i+1=>Down , j+1=>Right
        }
    }

    int uniquePath(int m, int n)
    {
        return countPath(0, 0, m, n);
    }
};

int main()
{
    Solution obj;
    int ans = obj.uniquePath(3, 7);
    cout << "Total No. Path Count: " << ans << endl;
    return 0;
}
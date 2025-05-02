
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int uniquePath(int m, int n)
    {
        int N = m + n - 2;
        int r = m - 1;
        double res = 1;

        for (int i = 1; i <= r; i++)
        {
            res = res * (N - r + i) / i;
        }
        return (int)res;
    }
};

int main()
{
    Solution obj;
    int ans = obj.uniquePath(3, 7);
    cout << "Total No. Path Count: " << ans << endl;
    return 0;
}
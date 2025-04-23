#include <bits/stdc++.h>
using namespace std;
double myPow(double x, int n)
{
    double ans = 1.0;
    long long nn = n;
    if (nn < 0)
    {
        nn = -nn;
    }
    while (nn > 0)
    {
        if (nn % 2 == 1)
        {
            // odd
            ans = ans * x;
            nn = nn - 1;
        }
        else
        {
            // even
            x = x * x;
            nn = nn / 2;
        }
    }
    if (n < 0)
    {
        ans = 1.0 / ans;
    }

    return ans;
}
int main()
{
    cout << myPow(2.0, 10) << endl;
    cout << myPow(2.0, 2) << endl;
    cout << myPow(2.0, 3) << endl;
    cout << myPow(2.0, 5) << endl;
    return 0;
}
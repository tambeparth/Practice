// bit manipulation
#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumber(vector<int> a)
{
    int n = a.size();
    int xr = 0;
    for (int i = 0; i < n; i++)
    {
        xr = xr ^ a[i];
        xr = xr ^ (i + 1);
    }

    // Find the differentiating bit number
    int number = (xr & ~(xr - 1));

    int zero = 0;
    int one = 0;
    for (int i = 0; i < n; i++)
    {
        if ((a[i] & number) != 0)
        {
            one = one ^ a[i]; // for 1 group
        }
        else
        {
            zero = zero ^ a[i]; // for 0 group
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if ((i & number) != 0)
        {
            one = one ^ i;
        }
        else
        {
            zero = zero ^ i;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == zero)
            cnt++;
    }
    if (cnt == 2)
        return {zero, one};
    return {one, zero};
}
int main()
{
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumber(a);
    cout << "The repeating and missing Number are:{"
         << ans[0] << " " << ans[1] << "}\n";
    return 0;
}
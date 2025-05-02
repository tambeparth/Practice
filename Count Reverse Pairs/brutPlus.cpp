
#include <bits/stdc++.h>
using namespace std;

int countPairs(vector<int> &a, int n)
{

    // Count the number of pairs:
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > 2 * a[j])
                cnt++;
        }
    }
    return cnt;
}

int team(vector<int> &skill, int n) // So this is a wrapper function — not necessary but used here to separate logic
{
    return countPairs(skill, n);
}

int main()
{
    vector<int> a = {3, 2, 1, 4};
    int n = 4;
    int cnt = team(a, n);
    cout << "The number of reverse pair is: "
         << cnt << endl;
    return 0;
}

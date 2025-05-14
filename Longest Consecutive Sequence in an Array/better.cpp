#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int LongestSeq(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
    {
        return 0;
    }
    int lastSmall = INT_FAST16_MIN;
    int cnt = 0;
    int longestSeq = 1;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] - 1 == lastSmall)
        {
            cnt += 1;
            lastSmall = arr[i];
        }
        else if (arr[i] != lastSmall)
        {
            cnt = 1;
            lastSmall = arr[i];
        }
        longestSeq = max(longestSeq, cnt);
    }
    return longestSeq;
}
int main()
{
    vector<int> arr = {100, 200, 1, 2, 3, 4};
    cout << "Longest Sequence: " << LongestSeq(arr);
    return 0;
}
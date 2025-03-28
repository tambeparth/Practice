// Kadane's Algorithm
#include <bits/stdc++.h>
using namespace std;
long long maxSubarr(int arr[], int n)
{
    long long maxi = INT_MIN;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum < 0)
        {
            sum = 0;
        }

        maxi = max(maxi, sum);
    }

    return maxi;
}

int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = maxSubarr(arr, n);
    cout << "Maximum value is :" << max << endl;
    return 0;
}
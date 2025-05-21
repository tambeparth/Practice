// Minimum Parity Difference — Change the parity of exactly one element in the
// array to minimize the absolute difference between the sum of even and odd numbers.
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int minimumParityDiff(int N, vector<int> &A)
{
    int n = A.size();
    long long even_sum = 0;
    long long odd_sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (A[i] % 2 == 0)
        {
            even_sum += A[i];
        }
        else
        {
            odd_sum += A[i];
        }
    }

    long long min_diff = abs(even_sum - odd_sum);

    for (int i = 0; i < n; i++)
    {
        int x = A[i];
        // Change A[i] to A[i] + 1
        int y = x + 1;
        long long new_even = even_sum;
        long long new_odd = odd_sum;
        if (x % 2 == 0)
        {
            new_even -= x;
            new_odd += y;
        }
        else
        {
            new_odd -= x;
            new_even += y;
        }
        min_diff = min(min_diff, abs(new_even - new_odd));

        if (x > 1)
        {
            y = x - 1;
            new_even = even_sum;
            new_odd = odd_sum;
            if (x % 2 == 0)
            {
                new_even -= x;
                new_odd += y;
            }
            else
            {
                new_odd -= x;
                new_even += y;
            }
            min_diff = min(min_diff, abs(new_even - new_odd));
        }
    }
    return min_diff;
}
int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        cout << minimumParityDiff(N, A) << endl;
    }
    return 0;
}
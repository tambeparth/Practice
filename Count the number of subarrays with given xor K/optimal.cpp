#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
int check(vector<int> &arr, int target)
{
    int n = arr.size();
    int count = 0;
    vector<int> prefixSum(n, 0);

    prefixSum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    unordered_map<int, int> m;
    for (int j = 0; j < n; j++)
    {
        if (prefixSum[j] == target)
            count++;

        int val = prefixSum[j] - target;
        if (m.find(val) != m.end())
        {
            count += m[val];
        }

        if (m.find(prefixSum[j]) == m.end())
        {
            m[prefixSum[j]] = 0;
        }
        m[prefixSum[j]]++;
    }
    return count;
}
int main()
{
    vector<int> arr = {9, 4, 20, 3, 10, 5};
    cout << "Count: " << check(arr, 33);
    return 0;
}
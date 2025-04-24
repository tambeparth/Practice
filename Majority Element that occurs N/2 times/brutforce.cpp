#include <bits/stdc++.h>
using namespace std;
int majorityElement(vector<int> &arr)
{
    int n = arr.size();

    unordered_map<int, int> freq;
    for (int num : arr)
    {
        freq[num]++;
    }
    for (auto &pair : freq)
    {
        if (pair.second > n / 2)
        {
            return pair.first; // return the key/element , paid.second return value/freq count
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    cout << majorityElement(arr);
    return 0;
}
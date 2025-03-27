#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3};
    if (next_permutation(arr.begin(), arr.end())) // inbuilt function used directly
    {
        cout << "Next Permutation:";
    }
    else
    {
        cout << "Smallest permutation:";
    }
    for (auto num : arr)
    {
        cout << num << " ";
    }
    return 0;
}

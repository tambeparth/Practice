#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
using namespace std;

bool check(vector<int> &arr, int num)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            return true;
        }
    }
    return false;
}
int longestSequence(vector<int> &arr)
{
    int n = arr.size();
    int maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        int currNum = arr[i];
        int currLen = 1;

        while (check(arr, currNum + 1))
        {
            currLen += 1;
            currNum += 1;
        }

        maxLen = max(maxLen, currLen);
    }
    return maxLen;
}

int main()
{
    vector<int> arr = {100, 4, 200, 1, 3, 2};
    cout << "Count is: " << longestSequence(arr);
    return 0;
}
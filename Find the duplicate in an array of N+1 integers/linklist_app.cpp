#include <bits/stdc++.h>
using namespace std;
int findDuplicate(vector<int> &arr)
{
    int slow = arr[0];
    int fast = arr[0];

    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];

    } while (slow != fast);

    slow = arr[0];
    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}
int main()
{
    vector<int> arr = {1, 3, 4, 2, 2};
    cout << "Duplicate Number is:" << findDuplicate(arr) << endl;
    return 0;
}
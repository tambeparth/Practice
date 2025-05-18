#include <iostream>
#include <vector>
using namespace std;

int check(vector<int> &arr, int k)
{
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int xorApp = 0;
        for (int j = i; j < n; j++)
        {
            xorApp ^= arr[j];
            if (xorApp == k)
            {
                count++;
            }
        }
    }
    return count++;
}
int main()
{
    vector<int> arr = {4, 2, 2, 6, 4};
    cout << check(arr, 6);
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
int countRev(vector<int> &arr)
{
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {

        for (int j = i + 1; j < n; j++)
        {
            if (i < j && arr[i] > 2 * arr[j])
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    vector<int> arr = {3, 2, 1, 4};
    cout << countRev(arr);
    return 0;
}
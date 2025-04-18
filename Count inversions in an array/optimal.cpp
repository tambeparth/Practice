#include <iostream>
#include <vector>
using namespace std;
long long merge(vector<int> &arr, vector<int> &temp, int left, int mid, int right)
{
    long long in_count = 0;
    int i = left;
    int j = mid + 1;
    int k = left;
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            in_count += (mid - i + 1);
        }
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= right)
    {
        temp[k++] = arr[j++];
    }
    for (int i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }
    return in_count;
}
// Recursive merge sort function to count inversions
long long mergeSort(vector<int> &arr, vector<int> &temp, int left, int right)
{
    long long inv_count = 0;
    if (left < right)
    {
        int mid = (left + right) / 2;

        inv_count += mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid + 1, right);

        inv_count += merge(arr, temp, left, mid, right);
    }
    return inv_count;
}
// Function to count inversions
long long countInversions(vector<int> &arr)
{
    vector<int> temp(arr.size());
    return mergeSort(arr, temp, 0, arr.size() - 1);
}
int main()
{
    vector<int> arr = {2, 4, 1, 3, 5};
    cout << "Original array: ";
    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << endl;

    long long res = countInversions(arr);
    cout << "Number of inversion:" << res << endl;
    return 0;
}
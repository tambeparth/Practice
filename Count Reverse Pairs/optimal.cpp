
#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left++]);
    }
    while (right <= high)
    {
        temp.push_back(arr[right++]);
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

int countPair(vector<int> &arr, int low, int mid, int high)
{
    int right = mid + 1;
    int cnt = 0;

    for (int i = low; i <= mid; i++)
    {
        while (right <= high && arr[i] > 2 * arr[right])
        {
            right++;
        }
        cnt += (right - (mid + 1));
    }
    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high)
{

    int cnt = 0;
    if (low >= high)
        return cnt;

    int mid = (low + high) / 2;

    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid + 1, high);
    cnt += countPair(arr, low, mid, high);
    merge(arr, low, mid, high);
    return cnt;
}

int main()
{
    vector<int> arr = {3, 2, 1, 4};
    int n = 4;
    int cnt = mergeSort(arr, 0, n - 1);
    cout << "The number of reverse pair is: " << cnt << endl;
    return 0;
}
#include <iostream>
using namespace std;

void swapIfNeeded(long long first[], long long second[], int index1, int index2)
{
    if (first[index1] > second[index2])
    {
        swap(first[index1], second[index2]);
    }
}

void mergeSortedArrays(long long first[], long long second[], int size1, int size2)
{
    int totalLength = size1 + size2;

    int gap = (totalLength / 2) + (totalLength % 2);

    while (gap > 0)
    {
        int left = 0;
        int right = left + gap;

        while (right < totalLength)
        {
            // Case 1: left in first[], right in second[]
            if (left < size1 && right >= size1)
            {
                swapIfNeeded(first, second, left, right - size1);
            }
            // Case 2: both in second[]
            else if (left >= size1)
            {
                swapIfNeeded(second, second, left - size1, right - size1);
            }
            // Case 3: both in first[]
            else
            {
                swapIfNeeded(first, first, left, right);
            }

            left++;
            right++;
        }

        if (gap == 1)
            break;

        gap = (gap / 2) + (gap % 2);
    }
}

int main()
{
    long long firstArray[] = {1, 4, 8, 10};
    long long secondArray[] = {2, 3, 9};
    int size1 = 4;
    int size2 = 3;

    mergeSortedArrays(firstArray, secondArray, size1, size2);

    cout << "The merged arrays are:\n";

    cout << "First Array: ";
    for (int i = 0; i < size1; i++)
    {
        cout << firstArray[i] << " ";
    }

    cout << "\nSecond Array: ";
    for (int i = 0; i < size2; i++)
    {
        cout << secondArray[i] << " ";
    }

    cout << endl;
    return 0;
}

// Approach 2: Optimized Approach (Using Row & Column Marker)
// This approach avoids extra function calls by using two
// arrays to keep track of which rows and columns should be zeroed out.
// It runs in O(N × M) time and O(N + M) space.

// Steps:
// Create two arrays row and col of size n and m, initialized with 0.
// Traverse the matrix, marking row[i] = 1 and col[j] = 1 if matrix[i][j] == 0.
// Traverse the matrix again, setting matrix[i][j] = 0 if row[i] == 1 or col[j] == 1.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void zeroMatrix(vector<vector<int>> &matrix, int n, int m)
{
    vector<int> row(n, 0), col(m, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] == 1 || col[j] == 1)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();

    zeroMatrix(matrix, n, m);
    cout << "The Final matrix is:\n";
    for (auto row : matrix)
    {
        for (auto col : row)
        {
            cout << col << " ";
        }
        cout << "\n";
    }
    return 0;
}
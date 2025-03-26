#include <iostream>
#include <vector>
using namespace std;
void zeroMatrix(vector<vector<int>> &matrix, int n, int m)
{

    bool firstRow = false;
    bool firstCol = false;

    for (int i = 0; i < n; i++)
    {
        if (matrix[i][0] == 0)
        {
            firstRow = true;
        }
    }

    for (int j = 0; j < m; j++)
    {
        if (matrix[0][j] == 0)
        {
            firstCol = true;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }
    if (firstRow)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[0][j] = 0;
        }
    }

    if (firstCol)
    {
        for (int i = 0; i < n; i++)
        {
            matrix[i][0] = 0;
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

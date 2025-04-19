#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int searchMat(vector<vector<int>> &mat, int target)
{
    int n = mat.size();
    int m = mat[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == target)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> mat = {{1, 2, 3, 4}, {5, 6, 7, 74}, {9, 10, 11, 12}};
    searchMat(mat, 8) == true ? cout << "true\n" : cout << "false\n";
    // return 0;
}
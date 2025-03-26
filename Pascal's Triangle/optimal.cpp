#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r)
{
    long long res = 1;
    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return (int)(res);
}

vector<vector<int>> pascalTringle(int n)
{
    vector<vector<int>> ans;

    for (int row = 1; row <= n; row++)
    {
        vector<int> tempLST;

        for (int col = 1; col <= row; col++)
        {
            tempLST.push_back(nCr(row - 1, col - 1));
        }
        ans.push_back(tempLST);
    }
    return ans;
}
int main()
{
    int n = 5;
    vector<vector<int>> ans = pascalTringle(n);

    for (auto it : ans)
    {
        for (auto col : it)
        {
            cout << col << " ";
        }
        cout << "\n";
    }
    return 0;
}

/*
Step-by-Step Dry Run:
Input:
int n = 5;
We need to generate Pascal’s Triangle up to 5 rows.

Execution Starts (main function):

vector<vector<int>> ans = pascalTringle(n);
Calls pascalTringle(5).

Step 1: pascalTringle(5) Execution
vector<vector<int>> ans;
ans is an empty 2D vector that will store the Pascal's Triangle.

Outer Loop:
Iterating Over Rows (row = 1 to n)

for (int row = 1; row <= n; row++)
Iteration 1 (row = 1)
tempLST → empty list []

Inner Loop (col = 1 to row)

nCr(row-1, col-1) = nCr(0,0)

Call nCr(0,0)

Calculating nCr(0,0)

res = 1
Loop does not run (as r = 0).

Return 1.

tempLST = [1]

Store in ans: ans = [[1]]

Iteration 2: (row = 2)
tempLST = []

Inner Loop (col = 1 to 2)

nCr(1,0) = 1

nCr(1,1) = 1

tempLST = [1, 1]

Store in ans: ans = [[1], [1, 1]]

Iteration 3:  (row = 3)
tempLST = []

Inner Loop (col = 1 to 3)

nCr(2,0) = 1

nCr(2,1) = 2

nCr(2,2) = 1

tempLST = [1, 2, 1]

Store in ans: ans = [[1], [1, 1], [1, 2, 1]]

Iteration 4: (row = 4)
tempLST = []

Inner Loop (col = 1 to 4)

nCr(3,0) = 1

nCr(3,1) = 3

nCr(3,2) = 3

nCr(3,3) = 1

tempLST = [1, 3, 3, 1]

Store in ans: ans = [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1]]

Iteration 5: (row = 5)
tempLST = []

Inner Loop (col = 1 to 5)

nCr(4,0) = 1

nCr(4,1) = 4

nCr(4,2) = 6

nCr(4,3) = 4

nCr(4,4) = 1

tempLST = [1, 4, 6, 4, 1]

Store in ans:


ans = [[1],
       [1, 1],
       [1, 2, 1],
       [1, 3, 3, 1],
       [1, 4, 6, 4, 1]]


Step 2: Printing the Pascal's Triangle

for (auto it : ans)
{
    for (auto col : it)
    {
        cout << col << " ";
    }
    cout << "\n";
}
Loops through ans, printing the values row-wise.

1
1 1
1 2 1
1 3 3 1
1 4 6 4 1

*/
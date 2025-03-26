// combination formula  binomial coefficient formula:
#include <iostream>
using namespace std;
long long binomialCoefficient(int n, int r) // n and r element of binomial coefficient formula nCr
{
    long long res = 1;
    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}
int main()
{
    int r, c;
    cout << "Enter row (r) and column (c)";
    cin >> r >> c;

    int n = r - 1;
    int m = c - 1;

    cout << "Element at position(" << r << ", " << c << ")is:" << binomialCoefficient(n, m) << endl;
    return 0;
}
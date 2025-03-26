#include <iostream>
using namespace std;
long long pascleTriangle(int n)
{
    long long ans = 1;
    cout << ans << " ";

    for (int i = 1; i < n; i++)
    {
        ans = ans * (n - i);
        ans = ans / i;
        cout << ans << " ";
    }
    cout << endl;
}
int main()
{
    int n = 10;
    pascleTriangle(n);
    return 0;
}
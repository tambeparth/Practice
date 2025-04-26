#include <iostream>
using namespace std;
void travereseinteger(int num)
{
    while (num != 0)
    {
        int digit = num % 10;
        cout << digit;
        num /= 10;
    }
    cout << endl;
}

int main()
{

    int num;
    cin >> num;
    travereseinteger(num);
}
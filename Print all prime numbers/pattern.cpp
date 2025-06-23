// Print the following pattern:
// 1
// 23
// 456
// 7890
// 12345
#include <iostream>
using namespace std;

int main()
{
    int currNum = 1;
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << currNum << " ";
            currNum++;

            if (currNum > 9)
            {
                currNum = 0;
            }
        }
        cout << endl;
    }
    return 0;
}
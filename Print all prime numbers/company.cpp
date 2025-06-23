// Print all prime numbers from 20 to 360 and skip one prime number between every two printed primes.
#include <iostream>
using namespace std;
bool isPrime(int num)
{
    if (num < 2)
        return false;
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int count = 0;
    cout << "Prime numbers from 20 to 360 (skipping one in between):\n";

    for (int i = 20; i < 360; i++)
    {
        if (isPrime(i))
        {
            if (count % 2 == 0)
            {
                cout << i << " ";
            }
            count++;
        }
    }
    cout << endl;
    return 0;
}
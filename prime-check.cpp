#include <iostream>

using namespace std;

bool is_prime(int);

int main()
{
    int num;

    cout << "Enter number to check: ";
    cin >> num;

    if (is_prime(num))
    {
        cout << num << " is Prime";
    }
    else
    {
        cout << num << " is Not Prime";
    }

    return 0;
}

bool is_prime(int num)
{
    for (int i = 2; i < num / 2; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

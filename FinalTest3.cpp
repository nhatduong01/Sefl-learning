#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
void CategorizeNumber(int number)
{
    int numDivisor = 0;
    for (int i = 1; i < number; i++)
    {
        if (number % i == 0)
            numDivisor += i;
    }
    if (numDivisor > number)
        cout << "This number is abundant " << endl;
    else if (numDivisor == number)
        cout << "This number is perfect " << endl;
    else
    {
        cout << "This number is deficient " << endl;
    }
}
bool IsPrime(int n)
{
    if (n == 1 || n == 2)
        return true;
    else
    {
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
                return false;
        }
    }
    return true;
}
void ExtractNumber(int number)
{
    if (IsPrime(number) == true)
    {
        cout << number;
        return;
    }
    vector<int> PrimeStorage;
    for (int i = 2; i < sqrt(number); i++)
    {
        if (IsPrime(i) == true)
            PrimeStorage.push_back(i);
    }
    auto i = PrimeStorage.begin();
    while (i != PrimeStorage.end() && number != 1)
    {
        if (number % (*i) != 0)
        {
            i++;
        }
        else
        {
            cout << (*i) << "\t";
            number /= (*i);
            i = PrimeStorage.begin();
        }
    }
}
void Palindrome(int number)
{
    string result = to_string(number);
    int size = result.length();
    if (size == 1)
    {
        return;
    }
    bool palindrome = true;
    // cout << "the size is : " << size << endl;
    if (size % 2 == 0)
    {
        int start = 0;
        int end = size - 1;
        while (end - start != -1)
        {
            if (result[end] != result[start])
            {
                palindrome = false;
                break;
            }
            end--;
            start++;
        }
    }
    else
    {
        int start = 0;
        int end = size - 1;
        while (end != start)
        {
            if (result[end] != result[start])
            {
                palindrome = false;
                break;
            }
            start++;
            end--;
        }
    }
    if (palindrome == true)
        cout << "This number is palindrome " << endl;
    else
    {
        cout << "This number is not palindrome " << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    cout << 1 << "\t";
    for (int i = 2; i < n / 2; i++)
        while (n % i == 0)
        {
            cout << i << "\t";
            n /= i;
        }
    if (n != 1)
        cout << n;
    system("pause");
    return 0;
}
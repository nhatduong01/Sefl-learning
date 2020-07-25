// CPP program to the nth prime number
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// initializing the max value
#define MAX_SIZE 1000005

// Function to generate N prime numbers using
// Sieve of Eratosthenes
unsigned long long numPrimorial(unsigned short int number)
{
    vector<int> primes;
    unsigned long long result = 1;
    bool IsPrime[MAX_SIZE];
    memset(IsPrime, true, sizeof(IsPrime));

    for (int p = 2; p * p < MAX_SIZE; p++)
    {
        // If IsPrime[p] is not changed, then it is a prime
        if (IsPrime[p] == true)
        {
            // Update all multiples of p greater than or
            // equal to the square of it
            // numbers which are multiple of p and are
            // less than p^2 are already been marked.
            for (int i = p * p; i < MAX_SIZE; i += p)
                IsPrime[i] = false;
        }
    }

    // Store all prime numbers
    for (int p = 2; p < MAX_SIZE; p++)
        if (IsPrime[p])
            primes.push_back(p);
    for (int i = 0; i < number; i++)
        result *= primes[i];
    return result;
}

// Driver Code
int main()
{
    // To store all prime numbers
    int position = 0;
    cout << "Please enter the position : ";
    cin >> position;
    cout << "The " << position << "th prime number is : " << numPrimorial(position) << endl;
    system("pause");
    return 0;
}

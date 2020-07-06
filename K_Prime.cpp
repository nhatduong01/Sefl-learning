// C++ program to print all prime factors
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

// A function to print all prime
// factors of a given number n
int primeFactors(int n)
{
    int kprime = 0;
    // Print the number of 2s that divide n
    if (n == 0)
        return 0;
    while (n % 2 == 0)
    {
        //cout << 2 << " ";
        n = n / 2;
        kprime++;
    }
    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            //cout << i << " ";
            n = n / i;
            kprime++;
        }
    }
    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        kprime++;
    return kprime;
}
class KPrimes
{
public:
    static std::vector<long long> countKprimes(int k, long long start, long long end);
    static int puzzle(int s);
};
vector<long long> KPrimes::countKprimes(int k, long long start, long long end)
{
    vector<long long> result;
    for (int i = start; i <= end; i++)
    {
        if (primeFactors(i) == k)
            result.push_back(i);
    }
    return result;
}
int KPrimes::puzzle(int s)
{
    int times = 0;
    vector<int> kprime1;
    vector<int> kprime3;
    vector<int> kprime7;
    for (int i = 2; i < s; i++)
    {
        if (primeFactors(i) == 1)
            kprime1.push_back(i);
    }
    for (int i = 2; i < s; i++)
    {
        if (primeFactors(i) == 3)
            kprime3.push_back(i);
    }
    for (int i = 2; i < s; i++)
    {
        if (primeFactors(i) == 7)
            kprime7.push_back(i);
    }
    for (auto i = kprime1.begin(); i != kprime1.end(); i++)
    {
        for (auto j = kprime3.begin(); j != kprime3.end(); j++)
        {
            for (auto k = kprime7.begin(); k != kprime7.end(); k++)
            {
                if (*i + *j + *k == s)
                    times++;
            }
        }
    }
    return times;
}
/* Driver code */
int main()
{
    KPrimes test;
    int start = 0;
    int end = 0;
    int distance = 0;
    vector<long long> results;
    cout << "Please enter the lower bound : ";
    cin >> start;
    cout << "Please enter the upper bound : ";
    cin >> end;
    cout << "Please enter the distance k : ";
    cin >> distance;
    results = test.countKprimes(distance, start, end);
    for (auto i = results.begin(); i != results.end(); i++)
    {
        cout << *i << '\t';
    }
    cout << endl;
    cout << "Please enter the number : ";
    int puzzle = 0;
    cin >> puzzle;
    cout << "There are " << test.puzzle(puzzle) << " possibilities. " << endl;
    system("pause");
    return 0;
}

// This is code is contributed by rathbhupendra

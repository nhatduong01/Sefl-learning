#include <iostream>
#include <string>
#include <math.h>
using namespace std;
class Carboat
{

public:
    static string howmuch(int m, int n);
};
string Carboat::howmuch(int m, int n)
{
    if (m >= n)
    {
        int temp = m;
        m = n;
        n = temp;
    }
    string result = "[";
    for (double i = m; i <= n; i++)
    {
        double Car, Boat;
        Car = static_cast<double>((i - 1.0) / 9.0);
        Boat = static_cast<double>((i - 2.0) / 7.0);
        if (Car == static_cast<int>(Car))
            if (Boat == static_cast<int>(Boat))
            {
                string tempI = to_string((int)i);
                string tempCar = to_string((int)Car);
                string tempBoat = to_string((int)Boat);
                result.append("[M: ");
                result.append(tempI);
                result.append(" B: ");
                result.append(tempBoat);
                result.append(" C: ");
                result.append(tempCar);
                result.append("]");
            }
    }
    result.append("]");
    return result;
}
int main()
{
    cout << "Please enter the lower bound : ";
    int LowerBound = 0;
    cin >> LowerBound;
    cout << "Please enter the upper bound : ";
    int UpperBound = 0;
    cin >> UpperBound;
    Carboat Result;
    cout << Result.howmuch(LowerBound, UpperBound) << endl;

    system("pause");
    return 0;
}

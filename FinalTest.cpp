#include <iostream>
#include <string>
using namespace std;
class Polynomials
{
private:
    unsigned int degree;
    int *Thepholy;

public:
    Polynomials(Polynomials const &temp)
    {
        cout << "The copy constructor is called " << endl;
        this->degree = temp.degree;
        this->Thepholy = new int[temp.degree + 1];
        for (int i = 0; i <= degree; i++)
            this->Thepholy[i] = temp.Thepholy[i];
    }
    Polynomials() // just for debug purpose
    {
        cout << "The defaut constructor is called " << endl;
        degree = 0;
        Thepholy = nullptr;
    }
    Polynomials(int _degree)
    {
        cout << "The constructor is called " << endl;
        if (_degree > 0)
            degree = _degree;
        Thepholy = new int[_degree + 1];
        for (int i = 0; i <= _degree; i++)
        {
            cout << "Please enter the coefficece at " << i << " : ";
            cin >> Thepholy[i];
        }
    }
    void PrintPoly()
    {
        string coeffience[] = {"", "x", "x^2", "x^3", "x^4", "x^5"};
        string result = "";
        for (int i = this->degree; i > 0; i--)
        {
            if (this->Thepholy[i] != 0)
            {
                result += to_string(this->Thepholy[i]);
                result += coeffience[i];
                result += " + ";
            }
        }
        if (this->Thepholy[0] != 0)
        {
            result += to_string(this->Thepholy[0]);
        }
        else
        {
            result.pop_back();
            result.pop_back();
        }
        cout << "The polynomial is : " << result << endl;
    }
    ~Polynomials()
    {
        degree = 0;
        cout << "Succesfully Deleted" << endl;
        if (Thepholy)
            delete[] Thepholy;
    }
    Polynomials operator*(const Polynomials &multiplier)
    {
        Polynomials Result;
        Result.degree = this->degree + multiplier.degree;
        Result.Thepholy = new int[Result.degree + 1];
        for (int i = 0; i <= Result.degree; i++)
            Result.Thepholy[i] = 0;
        for (int i = 0; i <= multiplier.degree; i++)
        {
            for (int j = 0; j <= this->degree; j++)
            {
                Result.Thepholy[i + j] += this->Thepholy[j] * multiplier.Thepholy[i];
            }
        }
        return Result;
    }
};
void printArr(int *arr, int size)
{
    int static i = 0;
    if (i == size)
        return;
    if (arr[i] > 0)
        cout << arr[i] << "\t";
    i++;
    printArr(arr, size);
}
void SumSymmetricEntry(int *arr, int size)
{
    static int start = 1;
    static int end = size;
    if (start != end)
        cout << arr[start - 1] + arr[end - 1] << "\t";
    if (start == end)
        cout << arr[start - 1] << "\t";
    start++;
    end--;
    if (start - end == 1 || start - end == 2)
        return;
    else
    {
        SumSymmetricEntry(arr, size);
    }
}
class Matrix
{

public:
    int numRow;
    int numCol;
    int **matrix;
    Matrix()
    {
        numRow = 0;
        numCol = 0;
        matrix = nullptr;
    }
    Matrix(int _numRow, int _numCol)
    {
        numCol = _numCol;
        numRow = _numRow;
        matrix = new int *[numRow];
        for (int i = 0; i < numRow; i++)
            matrix[i] = new int[_numCol];
        for (int i = 0; i < numRow; i++)
        {
            for (int j = 0; j < numCol; j++)
            {
                cout << "Please enter the value of matrix[" << i << "," << j << "] : ";
                cin >> matrix[i][j];
            }
        }
    }
    ~Matrix()
    {
        for (int i = 0; i < numRow; i++)
            delete[] matrix[i];
        delete[] matrix;
    }
};
Matrix MatrixMultiplication(Matrix A)
{
    Matrix B;
    B.numCol = A.numCol;
    B.numRow = 1;
    B.matrix = new int *[1];
    B.matrix[0] = new int[A.numCol];
    for (int i = 0; i < A.numCol; i++)
        B.matrix[0][i] = 0;
    for (int j = 0; j < A.numCol; j++)
    {
        for (int i = 0; i < A.numRow; i++)
            B.matrix[0][j] += A.matrix[i][j];
    }
    return B;
}
class Date
{
public:
    int day;
    int month;
    int year;
};
istream &operator>>(istream &input, Date &D)
{
    input >> D.day >> D.month >> D.year;
    return input;
}
ostream &operator<<(ostream &output, Date &D)
{
    output << D.day << "/" << D.month << "/" << D.year;
    return output;
}
int main()
{
    Polynomials Poly1(3);
    Polynomials Poly2(2);
    Polynomials Poly3 = (Poly1 * Poly2);
    Poly3.PrintPoly();
    // int number = 0;
    // cout << "Please enter the number of components of the array :";
    // cin >> number;
    // cout << "Please enter the array : ";
    // int *arr = new int[number];
    // for (int i = 0; i < number; i++)
    //     cin >> arr[i];
    // printArr(arr, number);
    // cout << endl;
    // SumSymmetricEntry(arr, number);
    // delete[] arr;
    // Matrix A(4, 3);
    // Matrix B = MatrixMultiplication(A);
    // for (int i = 0; i < B.numRow; i++)
    // {
    //     for (int j = 0; j < B.numCol; j++)
    //         cout << B.matrix[i][j] << "\t";
    // }
    // Date A;
    // cin >> A;
    // cout << A;
    system("pause");
    return 0;
}
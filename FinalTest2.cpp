#include <iostream>
#include <string.h>
#include <string>
using namespace std;
// struct tm
// {
//     int sec;
//     int min;
//     int hour;
//     int mday;
//     int mon;
//     int year;
// };
//struct a, b, c {int x; double y;} z;
class Father
{
public:
    Father() { cout << "Cha "; }
};
class Child : public Father
{
public:
    Child() { cout << "Con "; }
};
class MyClass
{
public:
    void Print() const { cout << 23; }
};
struct z
{
    int x;
    double y;
} a, b, c;
int func(void)
{
    cout << "duong " << endl;
    return 0.0;
}
void calcul(double a, int b, int c = 0)
{
    cout << "2" << endl;
}
void calcul(float a, float b)
{
    cout << "3" << endl;
}
int d = 1;
int func(int p)
{
    static int d = 15;
    d += p;
    cout << d << ";";
    return d;
}
int foo(int n)
{
    if (n == 0)
        return 0;
    return n * foo(n - 1);
}
void swap1(int c0[], int c1[])
{
    int t;
    t = c0[0];
    c0[0] = c1[0];
    c1[0] = t;
}
void swap2(int *c0, int *c1)
{
    int t;
    t = *c0;
    *c0 = *c1;
    *c1 = t;
}
void fun(int *a, int *b)
{
    int w;
    *a = *a + *a;
    w = *a;
    *a = *b;
    *b = w;
}

class A
{
public:
    A() { cout << "A"; }
    ~A() { cout << "a"; }
};
class B
{

public:
    A a;
    B() { cout << "B"; }
    ~B() { cout << "b"; }
};
int sumOddDigit(int n)
{
    static int sum = 0;
    if (n == 0)
        return sum;
    else
    {
        int temp = n % 10;
        if (temp % 2 == 1)
            sum += temp;
        n /= 10;
        return sumOddDigit(n);
    }
}
void Print(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j) //
                continue;
            if (a[i] % a[j] == 0)
            {
                cout << a[i] << "\t";
                break;
            }
        }
    }
}
class subject
{
private:
    int subjectID;
    string subjectName;
    float Midterm;
    float Finalterm;

public:
    void const getName()
    {
        cout << "The subject name is : " << subjectName << endl;
    }
    void const getID()
    {
        cout << "The subject ID is : " << subjectID << endl;
    }
    float const getMidterm()
    {
        return Midterm;
    }
    float const getFinalterm()
    {
        return Finalterm;
    }
    // subject()
    // {
    //     subjectID = 0;
    //     subjectName = "NoInformation";
    //     Midterm = 0;
    //     Finalterm = 0;
    // }
    subject(int _subjectID = 0, string _subjectName = "NoInformation", float _Midterm = 0, float _Finalterm = 0)
    {
        subjectID = _subjectID;
        subjectName = _subjectName;
        Midterm = _Midterm;
        Finalterm = _Finalterm;
    }
    void SetInformation(int _subjectID = 0, string _subjectName = "NoInformation", float _Midterm = 0, float _Finalterm = 0)
    {
        subjectID = _subjectID;
        subjectName = _subjectName;
        Midterm = _Midterm;
        Finalterm = _Finalterm;
    }
    float GPA()
    {
        return 0.4 * Midterm + 0.6 * Finalterm;
    }
    ~subject()
    {
    }
};
class Student
{
    int StudentID;
    int NumSubject;
    string StudentName;
    subject *Subject;

public:
    // Student()
    // {
    //     StudentID = 0;
    //     NumSubject = 0;
    //     StudentName = "No information ";
    //     Subject = nullptr;
    // }
    Student(int _StudentID = 0, int _Numobject = 0, string _StudentName = "No information")
    {
        StudentID = _StudentID;
        StudentName = _StudentName;
        if (_Numobject != 0)
        {
            Subject = new subject[_Numobject];
            NumSubject = _Numobject;
        }
        else
        {
            NumSubject = 0;
            Subject = nullptr;
        }
    }
    void Set(int _StudentID, int _Numobject, string _StudentName)
    {
        StudentID = _StudentID;
        StudentName = _StudentName;
        NumSubject = _Numobject;
        Subject = new subject[NumSubject];
        for (int i = 0; i < NumSubject; i++)
        {
            string tempname;
            cin.clear();
            cout << "Please enter the name of the subject (end with . character) : ";
            getline(cin, tempname, '.');
            int tempID;
            cout << "Please enter the ID of the subject : ";
            cin >> tempID;
            cout << "Please enter the midterm point : ";
            float tempMid;
            cin >> tempMid;
            cout << "Please enter your final point : ";
            float tempFinal;
            cin >> tempFinal;
            Subject[i].SetInformation(tempID, tempname, tempMid, tempFinal);
        }
    }
    subject *Getsubject()
    {
        return Subject;
    }
    void GetInformation()
    {
        cout << "The student ID is : " << StudentID << endl;
        cout << "the student's name is : " << StudentName << endl;
    }
    int const GetNumSubject()
    {
        return NumSubject;
    }
    ~Student()
    {
        delete[] Subject;
    }
};
void PrintHonorStudent(Student *list, int number)
{
    for (int i = 0; i < number; i++)
    {
        int num = list[i].GetNumSubject();
        subject *temp = new subject[num];
        for (int i = 0; i < num; i++)
        {
            temp[i] = (list[i].Getsubject())[i];
        }
        bool good = true;
        for (int j = 0; j < list[i].GetNumSubject(); j++)
        {
            if (temp[j].GPA() < 7)
            {
                good = false;
                break;
            }
            if (good == true)
                list[i].GetInformation();
        }
        delete[] temp;
    }
}
int main()
{

    //cout << sumOddDigit(1468952) << endl;
    //p->Print();
    int numberStudent = 0;
    cout << "Please enter the number of students : ";
    cin >> numberStudent;
    Student *list = new Student[numberStudent];
    for (int i = 0; i < numberStudent; i++)
    {
        int tempId = 0;
        cout << "Please enter the student ID : ";
        cin >> tempId;
        int numSubject = 0;
        cout << "Please enter the number of subjects that student learned : ";
        cin >> numSubject;
        string tempname;
        cin.clear();
        cout << "Please enter the student name (end with . character ) :  ";
        getline(cin, tempname, '.');
        list[i].Set(tempId, numSubject, tempname);
    }
    PrintHonorStudent(list, numberStudent);
    delete[] list;
    system("pause");
    return 0;
}
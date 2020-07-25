#include <iostream>
#include <string>
using namespace std;
class employee
{
public:
    employee()
    {
        id = 0;
        const string temp = "NoInformation";
        name = temp;
        salary = 0;
        count++;
    }
    employee(int _id, string _name, int _salary)
    {
        id = _id;
        name = _name;
        salary = _salary;
        count++;
    }

public:
    void GetName()
    {
        cout << "The name of the employee is : " << name << endl;
    }
    void GetId()
    {
        cout << "The id of the employee is : " << id << endl;
    }
    void GetSalary()
    {
        cout << "The salary of the employee is :" << salary << endl;
    }
    void GetNumber()
    {
        cout << "the number of emplyee is : " << count << endl;
    }

private:
    int id;
    string name;
    int salary;
    static int count;
};
int main()
{
    employee Duong(1952638, "Duong", 1000);
    Duong.GetName();
    system("pause");
    return 0;
}
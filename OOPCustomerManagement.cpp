#include <iostream>
#include <string>
using namespace std;
enum Card
{
    GoldenCard,
    SilverCard,
    NormalCard
};
class DateTime
{
public:
    int hour, miniute, second, day, month, year;
};
class Customer
{
public:
    Customer() //Default constructor
    {
        DateTime _date;
        _date.year = 0;
        _date.month = 0;
        _date.day = 0;
        name = "Unknown";
        Type = "Unknown";
        DateofBirth = _date;
        id = 0;
        TypeCard = NormalCard;
    }
    Customer(Customer &temp) // copy constructor
    {
        this->name = temp.name;
        this->Type = temp.Type;
        this->DateofBirth = temp.DateofBirth;
        this->id = temp.id;
        this->TypeCard = temp.TypeCard;
    }
    Customer(string _name, DateTime _DayofBirth, string _Type, int _id, Card _card)
    {
        name = _name;
        DateofBirth = _DayofBirth;
        Type = _Type;
        OrgName = "none";
        id = _id;
        TypeCard = _card;
    }
    Customer(string _name, DateTime _DateofBirth, string _OrgName, string _Type, int _id, Card _card)
    {
        name = _name;
        DateofBirth = _DateofBirth;
        Type = _Type;
        OrgName = _OrgName;
        id = _id;
        TypeCard = _card;
    }
    int id;
    string Type;
    string name;
    string nickname;
    string address;
    DateTime DateofBirth;
    int idTransaction;
    int Times;
    int *Cost;
    DateTime *Time;
    int TaxId;
    string OrgName;
    string OrgAddress;
    int Phone;
    int fax;
    string Email;
    string Website;
    Card TypeCard;
    void UpdateCard(Card Newcard)
    {
        TypeCard = Newcard;
    }
};
class CRM
{
public:
    Customer *customer;
    int NumOfCus;
    CRM(Customer *arrCus, int _NumOfCus)
    {
        customer = new Customer[_NumOfCus];
        for (int i = 0; i < _NumOfCus; i++)
            customer[i] = arrCus[i]; // Copy constructor is called here
        NumOfCus = _NumOfCus;
    }
    void AddCus(Customer NewCus)
    {
        int i = 0;
        do
        {
            if (NewCus.id == customer[i].id)
            {
                cout << "The customer's info have been stored\n";
                return;
            }
            i++;
        } while (i < NumOfCus);
        Customer *temp = new Customer[NumOfCus + 1];
        int k = 0;
        for (; k < NumOfCus; k++)
            temp[k] = customer[k];
        temp[k] = NewCus;
        customer = new Customer[NumOfCus + 1];
        for (int j = 0; j <= NumOfCus; j++)
            customer[j] = temp[j];
        delete[] temp;
    }
    Customer *FindingCustomer1(string Guest) //Using While loop
    {
        int i = 0;
        while (i < NumOfCus)
        {
            if (Guest == customer[i].name)
                return &customer[i];
            i++;
        }
        return nullptr;
    }
    Customer *FindingCustomer2(string Guest)
    {
        static int i = 0;
        if (i >= NumOfCus)
            return nullptr;
        if (Guest == customer[i].name)
            return &customer[i];
        else
        {
            i++;
            return FindingCustomer2(Guest);
        }
    }
};
int main()
{
    DateTime DuongBirth;
    DateTime Vingroup;
    DateTime Apple;
    DateTime buffet;
    buffet.day = 30;
    buffet.month = 8;
    buffet.year = 1930;
    Apple.day = 29;
    Apple.month = 2;
    Apple.year = 1980;
    Vingroup.day = 4;
    Vingroup.month = 2;
    Vingroup.year = 1996;
    DuongBirth.day = 30;
    DuongBirth.month = 8;
    DuongBirth.year = 2001;
    Customer Cus1("Duong", DuongBirth, "Individual", 1952638, SilverCard);
    Customer Cus2("Pham Nhat Vuong", Vingroup, "VinFast", "Organization", 23, GoldenCard);
    Customer Cus3("Steve Jobs", Apple, "Organization", 45, NormalCard);
    Customer Cus4("Warren Buffett", buffet, "Individual", 12, SilverCard);
    Customer List[3];
    List[0] = Cus1;
    List[1] = Cus2;
    List[2] = Cus3;
    CRM arr(List, 3);
    arr.AddCus(Cus3);
    arr.AddCus(Cus4);
    cout << arr.customer[2].name << endl;
    cout << arr.customer[3].name << endl;
    if (arr.FindingCustomer1("Duong"))
        cout << arr.FindingCustomer1("Duong")->id << endl;
    else
    {
        cout << "Not Found !!" << endl;
    }
    if (arr.FindingCustomer2("Pham Nhat Vuong"))
        cout << arr.FindingCustomer2("Pham Nhat Vuong")->id << endl;
    else
    {
        cout << "Not Found !!" << endl;
    }
    if (arr.FindingCustomer2("Mark Zuckerberg"))
        cout << arr.FindingCustomer2("Mark Zuckerberg")->id << endl;
    else
    {
        cout << "Not Found !!" << endl;
    }
    cout << "The Kind of member is : " << (Card)Cus1.TypeCard << endl;
    Cus1.UpdateCard(GoldenCard);
    cout << "The Kind of member is : " << (Card)Cus1.TypeCard << endl;
    system("pause");
    return 0;
}
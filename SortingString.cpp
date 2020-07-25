#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <sstream>
using namespace std;
class Dinglemouse
{
public:
    static vector<int> sort(const vector<int> &array);
};
void swap(string &a, string &b)
{
    string temp = a;
    a = b;
    b = temp;
}

// A function to implement bubble sort
void bubbleSort(vector<string> &arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
}
int extractIntegerWords(string str)
{
    stringstream ss;
    ss << str;
    string temp;
    int found;
    while (!ss.eof())
    {

        /* extracting word by word from stream */
        ss >> temp;

        /* Checking the given word is integer or not */
        if (stringstream(temp) >> found)
        {
            return found;
        }
    }
    return 0;
}
string convert_to_word(unsigned int number)
{
    int duong = number;
    if (number == 0)
        return "zero";
    string result = "";
    string units[10] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string ishteen[10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    string ishty[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    const string hundred = " hundred";
    int digit = log10(number) + 1;
    if (digit == 1)
    {
        result += units[number];
    }
    else if (digit == 2)
    {
        if (10 <= number && number <= 19)
            result += ishteen[number % 10];
        else
        {
            int temp = number / 10;
            result += ishty[temp];
            temp = number % 10;
            if (temp != 0)
                result += ' ';
            result += units[temp];
        }
    }
    else if (digit == 3)
    {
        int temp = number / 100;
        result += units[temp];
        result += hundred;
        if (number % 100 != 0)
        {
            result += ' ';
            number = number % 100;
            if (number >= 1 && number <= 9)
                result += units[number];
            else if (10 <= number && number <= 19)
                result += ishteen[number % 10];
            else
            {
                int temp = number / 10;
                result += ishty[temp];
                temp = number % 10;
                if (temp != 0)
                    result += ' ';
                result += units[temp];
            }
        }
    }
    result += ' ';
    result += to_string(duong);
    return result;
}
vector<int> Dinglemouse::sort(const vector<int> &array)
{
    vector<string> WordNums;
    for (auto i = array.begin(); i != array.end(); i++)
        WordNums.push_back(convert_to_word(*i));
    int size = array.size();
    bubbleSort(WordNums, size);
    vector<int> Result;
    for (int i = 0; i < size; i++)
        Result.push_back(extractIntegerWords(WordNums[i]));
    return Result;
}
int main()
{
    int number = 0;
    cout << "Please enter the elements of the array :";
    cin >> number;
    vector<int> Temp;
    int value = 0;
    for (int i = 0; i < number; i++)
    {
        cin >> value;
        Temp.push_back(value);
    }
    Dinglemouse Result;
    vector<int> duong;
    duong = Result.sort(Temp);
    for (auto i = duong.begin(); i != duong.end(); i++)
        cout << *i << "\t";
    cout << endl;
    system("pause");
    return 0;
}
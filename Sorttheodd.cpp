#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Kata
{
public:
    std::vector<int> sortArray(std::vector<int> &array)
    {
        for (int i = 0; i < array.size(); i++)
        {
            if (array[i] % 2 == 0 || array[i] == 0)
                continue;
            else
            {
                for (int j = i + 1; j < array.size(); j++)
                {
                    if (array[j] % 2 == 0 || array[j] == 0)
                        continue;
                    else
                    {
                        if (array[i] > array[j])
                        {
                            swap(array[i], array[j]);
                        }
                    }
                }
            }
        }
        return array;
    }
};
int main()
{
    int number = 0;
    cout << "Please enter the number of the array : ";
    cin >> number;
    Kata result;
    vector<int> temp;
    int value = 0;
    for (int i = 0; i < number; i++)
    {
        cin >> value;
        temp.push_back(value);
    }
    result.sortArray(temp);
    for (auto i = temp.begin(); i != temp.end(); i++)
        cout << *i << "\t";
    cout << endl;
    system("pause");
    return 0;
}

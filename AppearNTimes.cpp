#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> deleteNth(std::vector<int> arr, int n)
{
    for (auto i = arr.begin(); i != arr.end(); i++)
    {
        int times = count(arr.begin(), arr.end(), (*i));
        if (times > n)
        {
            while (times > n)
            {
                vector<int> deletedvalue = {(*i)};
                vector<int>::iterator index = find_end(arr.begin(), arr.end(), deletedvalue.begin(), deletedvalue.end());
                times--;
                arr.erase(index);
            }
        }
    }
    return arr;
}
int main()
{
    int size = 0;
    cout << "Please enter the size of the array : ";
    cin >> size;
    int value = 0;
    vector<int> result;
    for (int i = 0; i < size; i++)
    {
        cin >> value;
        result.push_back(value);
    }
    cout << "Please enter the maximun appearence : ";
    int appearence = 0;
    cin >> appearence;
    vector<int> temp = deleteNth(result, appearence);
    for (auto i = temp.begin(); i != temp.end(); i++)
        cout << (*i) << '\t';
    cout << endl;
    system("pause");
    return 0;
}
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<string, vector<string>> phonebook;
    phonebook["Rahul"].push_back("9110");
    phonebook["Rahul"].push_back("9111");
    phonebook["Rahul"].push_back("9112");
    phonebook["Kajal"].push_back("9210");
    phonebook["Kajal"].push_back("9211");
    phonebook["Kajal"].push_back("9212");

    for (auto p : phonebook)
    {
        cout << "Name: " << p.first << " -> ";
        for (string s : p.second)
        {
            cout << s << ",";
        }
        cout << "\n";
    }

    string name;
    cin >> name;

    if (phonebook.count(name) == 0)
    {
        cout << "Not Found";
    }
    else
    {
        for (string s : phonebook[name])
        {
            cout << s << "\n";
        }
    }

    return 0;
}
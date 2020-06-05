/*


Peter found a digital dictionary which is far better than normal dictionaries. The digital dictionary has an input field in which one can search any string and the dictionary displays all the words whose prefix is that input string in lexicographical order. Now you are given a task to make your own digital dictionary. You will be given words that you can store in your database and then you need to design the search functionality. And if no such words are available for a given search word, add this word to your dictionary.
Input Format

Single integer N which denotes the number of words which are to be stored in the database of the dictionary.
N lines of input, where in each line there is a string made up of lowercase/uppercase letter Single integer Q which denotes the number of queries.
Q number of lines describing the query string on each line given by user.
Constraints

1≤N≤30000
sum(len(stringi)) ≤ 2∗10^5
1≤Q≤10^3
Output Format

If word with prefix exists in the database, then you need to print all the words with the given prefix in lexicographical order in separate lines else you need to print "No suggestions" without the inverted commas.
Sample Input

4
pet
peter
rat
rack
5
pe
pet
r
rac
rat

Sample Output

pet
peter
pet
peter
rack
rat
rack
rat

Explanation

For query 1 : Input = "pe"
We print "pet" and "peter".
For query 2 : Input = "pet"
We print "pet" and "peter".
For query 3 : Input = "r"
We print "rack" and "rat".
For query 4 : Input = "rac"
We print "rat.
For query 5 : Input = "rat"
We print "rat". 
*/

#include <bits/stdc++.h>
using namespace std;
#define hashmap map<char, node *>
class node
{
public:
    char data;
    hashmap h;
    bool isterminal;

    node(char d)
    {
        data = d;
        isterminal = false;
    }
};
class trie
{
public:
    node *root;

    trie()
    {
        root = new node('\0');
    }
    void addword(string word)
    {
        node *temp = root;
        for (int i = 0; word[i] != '\0'; i++)
        {
            char ch = word[i];
            if (temp->h.count(ch) == 0)
            {
                node *child = new node(ch);
                temp->h[ch] = child;
                temp = child;
            }
            else
            {
                temp = temp->h[ch];
            }
        }
        temp->isterminal = true;
    }
    bool findtemp(string s)
    {
        node *temp = root;
        for (int i = 0; s[i] != '\0'; i++)
        {
            char ch = s[i];
            if (temp->h.count(ch) == 1)
            {
                temp = temp->h[ch];
            }
            else
            {
                return false;
            }
        }

        vector<string> v;
        print(s, v, temp);
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << endl;
        }
        return true;
    }

    void print(string s, vector<string> &v, node *temp)
    {
        if (temp->isterminal)
        {
            v.push_back(s);
        }
        for (auto i = temp->h.begin(); i != temp->h.end(); i++)
        {
            s += i->second->data;
            print(s, v, i->second);
            s.pop_back();
        }
    }
};

int main()
{
    int n;
    cin >> n;
    trie t;
    string s;
    while (n--)
    {
        cin >> s;
        t.addword(s);
    }
    int q;
    cin >> q;
    while (q--)
    {
        cin >> s;
        bool temp = t.findtemp(s);
        if (!temp)
        {
            cout << "No suggestions" << endl;
            t.addword(s);
        }
    }
    return 0;
}
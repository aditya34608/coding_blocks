#include <iostream>
#include <unordered_map>

using namespace std;

class Node{
public:
    char data;
    bool terminal;
    unordered_map<char, Node*> children;

    Node(char data){
        this -> data = data;
        this -> terminal = false;
    }
};

class Trie{
public:
    Node *root;
    int count;

    Trie(){
        this -> root = new Node('\0');
        this -> count = 0;
    }

    void addWord(string str){
        Node *temp = root;
        for (int i=0; i<str.size(); i++){
            char ch = str[i];
            if (temp -> children.count(ch)){
                temp = temp -> children[ch];
            }
            else{
                Node *n = new Node(ch);
                temp -> children[ch] = n;
                temp = n;
            }
        }
        temp -> terminal = true;
    }

    bool search(string str){
        Node *temp = root;
        for (int i=0; i<str.size(); i++){
            char ch = str[i];
            if (temp -> children.count(ch)){
                temp = temp -> children[ch];
            }
            else{
                return false;
            }
        }
        return temp -> terminal;
    }
};

int main(){
    ios_base::sync_with_stdio(false);

    Trie ob;
    int n;
    cin >> n;
    while(n--){
        string str;
        cin >> str;
        ob.addWord(str);
    }
    int q;
    cin >> q;
    while (q--){
        string str;
        cin >> str;
        cout << ob.search(str);
    }
    return 0;
}
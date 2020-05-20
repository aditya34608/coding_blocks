#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector< vector< int > > matrix(100, vector < int > (50, 100) );
    vector <int> d = {1, 2, 3, 10 , 14};

    //0(1) for most of time
    d.push_back(26);

    //remove last element 0(1)
    d.pop_back();

    cout << d.front() << "\n";
    cout << d.back() << "\n";

    //insert in middle 0(N)
    d.insert(d.begin() + 3, 4, 100);

    //erase some element in middle
    d.erase(d.begin() + 2);
    d.erase(d.begin() + 2, d.begin() + 5);

    //size
    cout << d.size() << "\n";
    cout << d.capacity() << "\n";

    //avoid shrink
    d.resize(18);
    cout << d.capacity() << "\n";

    //remove elements of vector, doesn't delete the memory
    d.clear();

    if (d.empty()){
        cout << "this is empty vector" << "\n";
    }

    cout << d.size() << "\n";

    for (int x:d){
        cout << x << ",";
    }
    cout << "\n";

    //reserve
    //v.reserve(1000);
    int n;
    cin >> n;
    vector <int> v;

    for (int i=0; i <n; i++){
        int no;
        cin >> no;
        v.push_back(no);
    }

    for (int x:v){
        cout << x << ",";
    }

    return 0;
}
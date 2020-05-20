#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    //creation and initialisation of vector
    vector <int> a;
    vector <int> b(5, 10); //int a vector of zeroes (n, 0)
    vector <int> c(b.begin(), b.end());
    vector <int> d{1, 2, 3, 10, 14};

    //interating over vector
    for (int i=0; i < c.size(); i++){
        cout << c[i] << ",";
    }
    cout << "\n";

    for (auto it = b.begin(); it != b.end(); it++){
        cout << (*it) << ",";
    }
    cout << "\n";

    //for each loop
    for (int x:d){
        cout << x << ",";
    }
    cout << "\n";

    vector<int> v;
    int n;
    cin >> n;
    for (int i=0; i< n; i++){
        int no;
        cin >> no;
        v.push_back(no);
    }
    for (int x:v){
        cout << x << ",";
    }
    cout << "\n";

    cout << v.size() << "\n";
    cout << v.capacity() << "\n";
    cout << v.max_size() << "\n";

    cout << d.size() << "\n";
    cout << d.capacity() << "\n";
    cout << d.max_size() << "\n";
    return 0;
}
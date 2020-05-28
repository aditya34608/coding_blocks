#include <iostream>
#include <map>

#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map <string, int> m;

    // 1. insert
    m.insert(make_pair("Mango", 100));

    pair <string, int> p;
    p.first = "Apple";
    p.second = 120;

    m.insert(p);

    m["Banana"] = 20;

    // 2. search
    string fruit;
    cin >> fruit;

    //update price
    m[fruit] += 2; 

    auto it = m.find(fruit);
    if (it != m.end()){
        cout << "price of " << fruit << " is " << m[fruit] << "\n";
    }
    else{
        cout << "fruit is not present " << "\n";
    }

    // 3. erase
    m.erase(fruit);

    //annother way to find particular key map
    // it stores unique keys

    if (m.count(fruit)){
        cout << "Price is " << m[fruit] << "\n";
    }
    else{
        cout << "couldn't find " << "\n";
    }

    m["Litchi"] = 60;
    m["Pineapple"] = 80;

    // iterate over all the key value pairs
    for (auto it = m.begin(); it != m.end(); it++){
        cout << it -> first << " and " << it -> second << "\n";
    }

    //for each loop
    for (auto p:m){
        cout << p.first << " : " << p.second << "\n";
    }

    return 0;
}
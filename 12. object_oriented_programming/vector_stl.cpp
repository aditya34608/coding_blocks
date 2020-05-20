#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b){
    cout << "comparing " << a <<  " and " << b << "\n";
    return a < b; //ascending order
    /*
    return a > b; //descending order
    */
}

int main(){

    int a[1000], n;
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    //function passed as parameters to sort function
    //compare ins't called here it's called internally
    sort(a, a+n, compare);

    for (int i=0; i < n; i++){
        cout << a[i] << ',';
    }

    return 0;
}
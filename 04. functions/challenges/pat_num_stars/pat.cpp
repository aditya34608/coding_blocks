#include <iostream>

using namespace std;

int main(){
    int n, j;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for ( j = 1; j <= i; j++){
            cout << j;
        }
        for (; j <= n ; j++){
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
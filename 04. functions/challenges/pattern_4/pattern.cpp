#include <iostream>

using namespace std;

int main(){
    int n, i, j;
    cin >> n;
    
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            if(i == 1 || i == n || j == 1 || j == i)
            {
                cout << "1" ;
            }
            else{
                cout << "0" ;
            }
        }
        cout << "\n";
    }
    return 0;
}
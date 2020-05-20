#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
    char ch;
    int d = 1;
    do{
        int n1, n2, ans;
        cin >> ch;
        switch (ch)
        {
        case '+': cin >> n1;
        cin >> n2;
        n1 = abs (n1);
        n2 = abs (n2);
        ans = n1 + n2;
        cout << ans << endl;
            break;
        case '-' : cin >> n1;
        cin >> n2;
        n1 = abs (n1);
        n2 = abs (n2);
        ans = n1 - n2;
        cout << ans << endl;
            break;
        case '*' : cin >> n1;
        cin >> n2;
        n1 = abs (n1);
        n2 = abs (n2);
        ans = n1 * n2;
        cout << ans << endl;
            break;
        case '/' : cin >> n1;
        cin >> n2;
        n1 = abs (n1);
        n2 = abs (n2);
        ans = n1 / n2;
        cout << ans << endl;
            break;                
        case '%' : cin >> n1;
        cin >> n2;
        n1 = abs (n1);
        n2 = abs (n2);
        ans = n1 % n2;
        cout << ans << endl;
            break;

        case 'x' : d = 0;
            break;
        case 'X' : d = 0;
            break;
        default : cout << "Invalid operation. Try again" << endl;
            break;    
        }
    }while (d!=0);
    {
        return 0;
    }
}
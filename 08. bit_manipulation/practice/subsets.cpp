/*Finding subsequences:
 Input - abc
 Output - " ", a, ab, abc, ac, b, bc, c
*/

#include <bits/stdc++.h>

using namespace std;

void filterChar(int n, char a[]){
    int j = 0;
    while (n > 0){
        int last_bit = (n & 1);
        if (last_bit){
            cout << a[j];
        }
        j++;
        n = n >> 1;
    }
    cout << "\n";
}

void printsubsets(char a[]){
    int n = strlen(a);
    for (int i = 0; i < (1 << n); i++){
        filterChar(i, a);
    }
    return;
}

int main(){
    char a[100];
    cin >> a;
    printsubsets(a);
    return 0;
}

/*
Take N (number in decimal format). Write a function that converts it to octal format. Print the value returned.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n, oct = 0, rem;
    cin >> n;
    int count = 0;

    int p = 1;
    while (n!= 0){
        rem = n % 8;
        oct = oct + rem * pow(10, count);
        n = n / 8;
        count ++;
    }
    cout << oct;
    return 0;
}
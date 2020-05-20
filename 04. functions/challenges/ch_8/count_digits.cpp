/* 
Take the following as input.
A number
A digit
Write a function that returns the number of times digit is found in the number. Print the value returned.
*/

#include <iostream>

using namespace std;

int main(){
    int numb, f_no;
    cin >> numb;
    cin >> f_no;
    int sumn = 0;
    while (numb > 0){
        int r = numb % 10;
        int x = f_no ^ r;
        if (x == 0){
            sumn += 1;
        }
        numb = numb / 10;
    }
    cout << sumn << endl;
    return 0;
}
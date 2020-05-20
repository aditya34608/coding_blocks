#include <iostream>

using namespace std;

int main(){
    int a = 10;
    cout << &a << "\n";

    float y = 10.5;
    cout << &y << "\n";

    //it doesn't work for character
    char ch = 'A';

    //eplicit typecasting from char* to void*
    cout << (void*) &ch << "\n";
    return 0;
}
#include <iostream>
using namespace std;

//pass by value
void increment(int a){
    a = a + 1;
    cout << "Inside Function: " <<a << "\n"; 
}

//pass by reference
void increment_1 (int *a){
    a = a + 1;
    cout << "Inside Reference " << a << "\n";
}

//pass by reference using pointers
void increment_2 (int *aptr){
    *aptr = *aptr + 1;
    cout << "Inside Reference by Pointer " << *aptr << "\n";
}

int main(){
    int a = 10;
    increment(a);
    increment_1(&a);
    increment_2(&a);
    cout << "Inside Main: " << a;
    return 0;
}
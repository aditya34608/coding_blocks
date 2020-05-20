#include <bits/stdc++.h>

using namespace std;

class  Car{
public:
    int price;
    int model_no;
    char name[20];
};


int main(){
    Car C;
    cout << sizeof(C) << "\n"; //actual object taking 28 bytes
    cout << sizeof(Car) << "\n"; //doesn't takes memory

    //Car C[100]-; //array of objects
    return 0;
}
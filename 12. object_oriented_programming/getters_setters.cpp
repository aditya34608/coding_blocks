#include <bits/stdc++.h>

using namespace std;

class Car{
private:
    int price;

public:
    int model_no;
    char name[20];

    void start(){
        cout << "Grrr... starting the car " << name << "\n";
    }
    void setPrice(int p){
        if (p > 1000){
            price = p;
        }
        else{
            price = 1000;
        }
    }
    int getPrice(){
        return price;
    }
};

int main(){
    Car C;
    C.setPrice(-500);
    C.model_no = 1001;
    C.name[0] = 'B';
    C.name[1] = 'M';
    C.name[2] = 'W';
    C.name[3] = '\0';
    C.start();   

    cout << C.name << "\n";
    cout << C.getPrice() << "\n";

    Car D;
    D.setPrice(2000);
    cout << C.getPrice() << "\n";

    return 0;
}
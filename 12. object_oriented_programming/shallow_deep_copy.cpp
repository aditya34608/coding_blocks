#include <iostream>
#include <cstring>
using namespace std;

class Car{
private:
    int price;
public:
    int model_no;
    char *name;
    
    //Constructor 
    Car(){
        //Override the default Constructor
        name = NULL;
        cout<<"Making a car.."<<"\n";
    }
    // Constructor with parameters - Parametrised Constructor 
    Car(int p,int mn,char *n){
        price = p;
        model_no = mn;
        int l  = strlen(n);
        name = new char[l+1];
        strcpy(name,n);
    }
   
   //Deep Copy Constructor 
    Car(Car &X){
    // cout<<"Making a Copy of Car";
        price = X.price;
        model_no = X.model_no;
        int l = strlen(X.name);
        name = new char[l+1];
        strcpy(name,X.name);
    }
    
    void setName(char *n){
        if(name==NULL){
            name = new char[strlen(n)+1];
            strcpy(name,n);
        }
        else{
            //Later...
            //Delete the oldname array and allocate a new one.
        }
    }
    
    void start(){
        cout<<"Grrrr...starting the car "<<name<<"\n";
    }
    void setPrice(int p){
        if(p>1000){
            price  = p;
        }
        else{
            price = 1000;
        }
    }
    int getPrice(){
        return price;
    }
    void print(){
        cout<<name<<"\n";
        cout<<model_no<<"\n";
        cout<<price<<"\n";
        cout<<"\n";
    }
};

int main() {
    
    Car C;
    //Initialisation
    //C.price =-500;
    C.setPrice(1500);
    C.setName((char*)"Nano");
    C.model_no = 1001;
    //C.start();
    C.print();
    
    Car D(100,200,(char*)"BMW");
    
    Car E(D); //Default Copy Constructor
    E.name[0] ='G';
    
    D.print();
    E.print();
    return 0;
}
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
        cout << "Making a car.." << "\n";
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
    
    void operator = (Car &X){
        cout << "In Copy Assignment Operator" << "\n";
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
        cout<<"Grrrr...starting the car " << name << "\n";
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
        cout << name << "\n";
        cout << model_no << "\n";
        cout << price << "\n";
        cout << "\n";
    }
    ~Car(){
        cout<<"Destroying the Car "<<name<<"\n";
        //Write code to delete all dynamic data member
        if(name!=NULL){
            delete [] name;
        }
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
    
    Car E(200,400,(char*)"Audi") ;//Default Copy Constructor
   
   // E.name[0] ='G';
    D = E; //Copy Assigment Operator ->Shallow Copy 
    D.name[0] = 'O';
    D.print();
    E.print();
    
    //Suppose we create a dynamic object 
    Car *DC = new Car(100,200,(char*)"Dynamic Tesla Car");
    delete DC;
    return 0;
}
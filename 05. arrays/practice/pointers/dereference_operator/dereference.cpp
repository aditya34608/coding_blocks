#include <iostream>
using namespace std;
int main(){
    int x = 10;
    int *xptr;
    xptr = &x;

    cout << &x << "\n";
    cout << xptr << "\n";

    cout << *(&x) << "\n";
    cout << *(xptr) << "\n";

    cout << *(&xptr) << "\n";
    cout << &(*xptr) << "\n";

    cout << &xptr << "\n";

    //pointer to a pointer
    int **xxptr = &xptr;
    cout << xxptr << "\n";

    return 0;
}
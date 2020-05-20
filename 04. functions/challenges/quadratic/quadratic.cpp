#include <iostream>
#include <cmath>
using namespace std;

int main() {

    float a, b, c, x1, x2, discriminant, realPart, imaginaryPart;
    cin >> a >> b >> c;
    discriminant = b*b - 4*a*c;
    
    if (discriminant > 0) {
        x1 = (-b + sqrt(discriminant)) / (2*a);
        x2 = (-b - sqrt(discriminant)) / (2*a);
        cout << "Real and Distinct" << endl;
        cout << x2 << " "<< x1 << endl;
    }
    
    else if (discriminant == 0) {
        cout << "Real and Same" << endl;
        x1 = (-b + sqrt(discriminant)) / (2*a);
        cout << x2 << " " << x1 << endl;
    }

    else {
        realPart = -b/(2*a);
        imaginaryPart =sqrt(-discriminant)/(2*a);
        cout << "Imaginary" << endl; 
    }
    return 0;
}
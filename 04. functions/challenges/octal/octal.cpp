#include <iostream> 
using namespace std; 

int binaryToDecimal(int n) 
{ 
	int num = n, dec_value = 0, base = 1, temp = num;

	while (temp) { 
		int last_digit = temp % 10; 
		temp = temp / 10; 

		dec_value += last_digit * base; 

		base = base * 2; 
	} 

	return dec_value; 
} 

int main() 
{ 
	int num;
    cin >> num; 

	cout << binaryToDecimal(num) << endl; 
}
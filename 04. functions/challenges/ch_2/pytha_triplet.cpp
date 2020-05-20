#include <iostream> 
using namespace std; 

void evaluate(long long int n) 
{ 
    if (n == 1 || n == 2) 
		cout << "-1"; 

	else if (n % 2 == 0) {
		long long int var = 1LL * n * n / 4; 
		cout << var - 1 << " " << var + 1; 
	} 

	else if (n % 2 != 0) { 
        long long int var = 1LL * n * n + 1; 
		cout << var / 2 - 1 << " " << var / 2; 
	} 
} 

// Driver function 
int main() 
{ 
	long long int n;
    cin >> n; 
	evaluate(n); 
	return 0; 
} 

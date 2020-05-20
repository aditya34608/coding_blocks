#include<bits/stdc++.h> 
using namespace std; 

void fib(int f[], int N) 
{
    f[1] = 1; 
	f[2] = 1; 
	
	for (int i = 3; i <= N; i++) 
        f[i] = f[i - 1] + f[i - 2]; 
} 

void fiboTriangle(int n) 
{ 
	int N = n*(n+1)/2; 
	int f[N + 1]; 
	fib(f, N); 
	int fiboNum = 0; 
	for (int i = 1; i <= n;i++) 
	{ 
		for (int j = 1;j <= i;j++) 
			cout << f[fiboNum++] << " "; 
			
		cout << endl; 
	} 
} 

int main() 
{ 
	int n;
    cin >> n; 
	fiboTriangle(n); 
	return 0; 
}
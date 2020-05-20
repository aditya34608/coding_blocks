#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int p[1000005] = {0};
/* 
naive approach (Time Complexity : O(N) if i < n)
O(sqrt(N)) if i * i

bool isPrime(int n){
    if (n == 1){
        return false;
    }
    else if (n == 2){
        return false;
    }
    for (int i=2; i * i < n; i++){
        if (n % i == 0){
            return false;
        }
        return true;
    }
}
*/

//Sieve approach - generate array containing prime no
void prime_sieve(int *p, int n){
    //mark all odd numbers prime
    for (int i = 3; i <= 1000000; i += 2){
        p[i] = 1;
    }

    //Sieve
    for (ll i = 3; i <= 1000000; i += 2){
        //if the current no is not marked (it's prime)
        if (p[i] == 1){
            // mark all the multiples of i as not prime
            for (ll j = i * i; j <= 1000000; j = j+i){
                p[j] = 0;
            }
        }
    }
    p[2] = 1;
    p[1] = p[0] = 0;
}

int main(){
    int n;
    cin >> n;

    prime_sieve(p, n);

    for (int i = 0; i <= n; i++){
        if (p[i] == 1){
            cout << i << " ";
        }
    }
}
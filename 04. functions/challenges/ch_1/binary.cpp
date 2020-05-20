#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    while (N > 0){
        int n, p = 1, ans = 0; 
        cin >> n;
        while (n >0){
            int r = n % 10;
            ans = ans + r * p;
            p = p * 2;
            n = n / 10;
    }
    cout << ans<< endl;
    N = N - 1;
    }
    return 0;
}
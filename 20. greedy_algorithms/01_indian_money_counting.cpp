#include <iostream>
#include <algorithm>

using namespace std;

int make_change(int *coins, int n, int money){
    int ans = 0;

    while(money > 0){
        int id = upper_bound(coins, coins+n, money) - 1 - coins;

        money = money - coins[id];
        ans += 1;
    }
    return ans;
}

int main() {
    //Indian Coin Change
    int money;
    cin >> money;
    
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int t = sizeof(coins) / sizeof(int);
    cout << "Coins needed " << make_change(coins, t, money) << "\n";

    return 0;
}

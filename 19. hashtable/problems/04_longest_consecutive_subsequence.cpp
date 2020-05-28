#include <iostream>
#include <unordered_set>

using namespace std;

int longest_consecutive_subsequence(int *arr, int n){
    unordered_set <int> mp;
    for (int i=0; i<n; i++){
        mp.insert(arr[i]);
    }
    int ans = 0;
    for (int i=0; i<n; i++){
        if (mp.find(arr[i] - 1) != mp.end()){
            continue;
        }
        else{
            int count = 0;
            int p = arr[i]; //left boundry
            while(mp.find(p) != mp.end()){
                count++;
                p++;
            }
            ans = max(ans, count);
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i=0; i < n; i++){
        cin >> arr[i];
    }
    cout << longest_consecutive_subsequence(arr, n) << "\n";
    return 0;
}
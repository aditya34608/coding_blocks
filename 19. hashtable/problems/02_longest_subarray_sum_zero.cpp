#include <iostream>
#include <unordered_map>

using namespace std;

int longest_subarray_sum(int *arr, int n){
    unordered_map <int , int> mp;
    int pre, len = 0;
    for (int i = 0; i< n; i++){
        pre += arr[i];
        if (arr[i] == 0 and len == 0) len = 1;
        if (pre == 0) len = max(len, i+1);
        if (mp.find(pre) != mp.end()){
            len = max(len, i - mp[pre]);
        }
        else{
            mp[pre] = i;
        }
    }
    return len;
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i =0; i < n; i++){
        cin >> arr[i];
    }
    cout << longest_subarray_sum(arr, n) << "\n";
    return 0;
}
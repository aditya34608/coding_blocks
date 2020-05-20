#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
    int arr[] = {20, 30, 40, 40, 40, 50, 100, 1000};
    int n = sizeof(arr) / sizeof(int);

    int key;
    cin >> key;

    bool present = binary_search(arr, arr+n, key);
    if (present){
        cout << "Present ";
    }
    else{
        cout << "Not Present ";
    }

    //lb function returns address of the key
    auto it = lower_bound(arr, arr+n, 50);
    printf("the lb of %d is %d \n", key, (it - arr)); // to get index of the key

    auto it_2 = upper_bound(arr, arr+n, 50);
    printf("the ub of %d is %d \n", key, (it - arr)); // to get index of the key

    printf("occurence frequency of is %d \n", (it_2 - it));
    return 0;
}

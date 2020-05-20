#include <iostream>

using namespace std;

auto find(int a[], int n, int key){
    int s = 0, e = n-1;
    while (s <= e){
        int mid = (s + e) / 2;
        if (a[mid] == key){
            return mid;
        }
        else if(a[s] <= a[mid]){
            //2 cases -> element lies in left or right
            if (key >= a[s] and key <= a[mid]){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        else{
            if (key >= a[mid] and key <= a[e]){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
    }
    return -1;
}

int main(){
    int n, key, a[100000];
    cin >> n;

    for (int i=0; i < n; i++){
        cin >> a[i];
    }
    cin >> key;
    cout << find(a, n, key) << "\n";
}
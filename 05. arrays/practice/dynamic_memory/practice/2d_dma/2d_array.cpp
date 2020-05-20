#include <iostream>

using namespace std;

int main(){
    int **arr = new int *[3];
    for (int i = 0; i < 3; i++){
        arr[i] = new int[4];
    }
    int count = 0;
    for (int i=0; i < 3; i++){
        for (int j=0; j< 4; j++){
            arr[i][j] = count;
            count++;
        }
    }
    for (int i=0; i < 3; i++){
        for (int j=0; j < 4; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    for (int i=0; i < 3; i++){
        delete arr[i];
    }
    delete []arr;
    cout << "deleted ";
    return 0;
}
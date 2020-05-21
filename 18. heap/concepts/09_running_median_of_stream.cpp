#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// function to calculate median of stream
void print_medians(double arr[], int n){
    
    // max heap to store the smaller half elements
    priority_queue<double> s;

    // min heap to store the smaller half element
    priority_queue<double, vector <double>, greater <double> > g;

    double med = arr[0];
    s.push(arr[0]);

    cout << med << "\n";

    /* 
    reading elements of stream one by one 
    At any time we try to make heaps balanced and their sizes differ by at-most 1. If heaps are 
    balanced,then we declare median as average of min_heap_right.top() and max_heap_left.top() 
    If heaps are unbalanced, then median is defined as the top element of heap of larger size.  
    */

    for (int i = 1; i < n; i++){
        double y = arr[i];

        // case 1: left side has more elements
        if (s.size() > g.size()){
            if (y < med){
                g.push(s.top());
                s.pop();
                s.push(y);
            }

            else{
                g.push(y);
            }
            med = (s.top() + g.top()) / 2.0;
        }

        // case 2: both heaps are balanced
        else if (s.size() == g.size()){
            if (y < med){
                s.push(y);
                med = (double)s.top();
            }
            else{
                g.push(y);
                med = (double)g.top();
            }
        }

        // case 3: right heap has more elements
        else{
            if (y > med){
                s.push(g.top());
                g.pop();
                g.push(y);
            }
            else{
                s.push(y);
            }
            med = (s.top() + g.top()) / 2.0;
        }

        cout << med << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double arr[] = {5, 15, 10, 20, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    print_medians(arr, n);
    return 0;
}
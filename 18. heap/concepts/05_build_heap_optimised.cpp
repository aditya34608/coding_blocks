#include <iostream>
#include <vector>

using namespace std;

void downheapify(vector <int> &heap, int id){
    int leftid = 2 * id + 1;
    int rightid = 2 * id + 2;
    if (leftid >= heap.size() and rightid >= heap.size()){
        return;
    }

    int largestid = id;
    if (leftid < heap.size() and heap[leftid] > heap[largestid]){
        largestid = leftid;
    }
    if (rightid < heap.size() and heap[rightid] > heap[largestid]){
        largestid = rightid;
    }

    if (largestid == id){
        return;
    }
    swap(heap[id], heap[largestid]);
    downheapify(heap, largestid);
}

void builheapoptimised(vector <int> &heap){
    for(int i=0; i<heap.size(); i++){
        downheapify(heap, i);
    }
}

void display(vector <int> &heap){
    for (int i=0; i<heap.size(); i++){
        cout << heap[i] << " ";
    }
    cout << "\n";
}

int main(){
    vector <int> heap;
    int n;
    cin >> n;
    for (int i=0; i < n; i++){
        int x;
        cin >> x;
        heap.push_back(x);
    }
    builheapoptimised(heap);
    display(heap);    
    return 0;
}
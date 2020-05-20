#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void heapify(vector <int> &heap, int id){
    if (id == 0){
        return;
    }
    int parent_id = (id - 1) / 2;
    if (heap[parent_id] < heap[id]){
        //swap
        int temp = heap[parent_id];
        heap[parent_id] = heap[id];
        heap[id] = temp;
        heapify(heap, parent_id);
    }
    else{
        return;
    }
}

void insert(vector <int> &heap, int key){
    heap.push_back(key);
    heapify(heap, heap.size() - 1);
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
        insert(heap, x);
    }
    display(heap);
    return 0;
}
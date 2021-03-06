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

void deletepeek(vector <int> &heap){
    swap(heap[0], heap[heap.size() - 1]);
    heap.pop_back();
    downheapify(heap, 0);
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
    deletepeek(heap);
    display(heap);
    return 0;
}
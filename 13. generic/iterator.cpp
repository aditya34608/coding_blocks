#include <iostream>
#include <list>

using namespace std;

//linear search
template<typename T>
int search(T arr[], int n, T key){
    for (int p=0; p < n; p++){
        if (arr[p]== key){
            return p;
        }
    }
    return n;
}

template <class ForwardIterator, class T>
ForwardIterator search(ForwardIterator start, ForwardIterator end, T key){
    while (start != end){
        if (*start == key){
            return start;
        }
        start++;
    }
}

int main(){
    list <int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    
    auto it = search(l.begin(), l.end(), 4);
    if (it == l.end()){
        cout << "element not found" << "\n";
    }
    else{
        cout << *it << "\n";
    }
    return 0;
}
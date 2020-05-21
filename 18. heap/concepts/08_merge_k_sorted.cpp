#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair <int, pair <int, int>> cp;

vector<int> merge_sorted_array(vector <vector <int>> arr){
    vector <int> result;
    priority_queue<cp, vector <cp>, greater <cp>> pq;
    for (int i=0; i<arr.size(); i++){
        pq.push ({arr[i][0], {i,0}});
    }
    while (pq.empty() == false){
        cp curr = pq.top();
        pq.pop();
        int x = curr.second.first;
        int y = curr.second.second;
        result.push_back(curr.first);
        if (y+1 < arr[x].size()){
            pq.push({arr[x][y+1], {x, y+1}});
        }
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector <vector <int>> arr{ {2, 6, 12, 15}, 
                                {1, 9, 13, 15}, 
                                {20, 24, 30, 32},
                                {-1, 3, 4, 5}};
    vector <int> output = merge_sorted_array(arr);
    for (auto x:output){
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}
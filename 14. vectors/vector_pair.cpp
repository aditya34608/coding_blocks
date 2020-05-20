#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

bool compare(pair <int, int> p1, pair<int, int> p2){
    int d1 = p1.first*p1.first + p1.second*p1.second;
    int d2 = p2.first*p2.first + p2.second*p2.second;

    if (d1 == d2){
        return p1.first < p2.first;
    }
    return d1 < d2;
}

int main(){
    int n;
    cin >> n;

    vector <pair<int, int>> d;

    for (int i=0; i< n; i++){
        int x, y;
        cin >> x >> y;
        d.push_back(make_pair(x, y));
    }

    sort(d.begin(), d.end(), compare);

    for (auto x:d){
        cout << "Car " << x.first << " " << x.second << "\n";
    }

    return 0;
}
/*
You are at a casino. There are N stacked cards on pile . Each card has a number written on it. Then there will be Q iterations. In ith iteration, you start picking up the cards in Ai-1th pile from the top one by one and check whether the number written on the card is divisible by the ith prime number. If the number is divisible, you stack that card on pile Bi. Otherwise, you stack that card on pile Ai. After Q iterations, cards can only be on pile B1, B2, B3, . . . BQ, AQ . Output numbers on these cards from top to bottom of each piles in order of B1, B2, B3, . . . BQ, AQ .
Input Format

First line contains N and Q. The next line contains N space separated integers representing the initial pile of cards i.e., A0. The leftmost value represents the bottom plate of the pile.

Constraints

N < 10^5

Output Format

Output N lines, each line containing the number written on the card.
Sample Input

5 1
3 4 7 6 5

Sample Output

4
6
3
7
5

Explanation

Initially:

A0 = [3, 4, 7, 6, 5]<-TOP

After 1st iteration:

A0 = []<-TOP

A1 = [5, 7, 3]<-TOP

B1 = [6, 4]<-TOP

Now first print B1 from top to bottom then A1 from top to bottom.

*/
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
    int q, n, v, cur_n, ele;
    vector <int> seive;
    seive.push_back(2);
    seive.push_back(3);
    stack <int> s1, s2, s3;
    for (int i=5; i<=1000; i++){
        int no = 0;
        for (int j = 2; j*j <= i; j++){
            if ((i % j) == 0){
                no = 1;
            }
        }
        if (!no){
            seive.push_back(i);
        }
    }

    cin >> n >> q;
    for (int i=0; i<n; i++){
        cin >> v;
        s1.push(v);
    }
    for (int i=0; i< q; i++){
        if (s1.empty()){
            break;
        }
        cur_n = seive[i];
        while (!s1.empty()){
            ele = s1.top();
            s1.pop();
            if (ele % cur_n == 0){
                s2.push(ele);
            }
            else{
                s3.push(ele);
            }
        }
        while(!s2.empty()){
            cout << s2.top() << "\n";
            s2.pop();
        }
        s1 = s3;
        //Correction:
        while (!s3.empty()){
            //You are not required to print this everytime.
            //Read the question carefully.
            // cout << s1.top() << "\n";

            //Leading to TLE.
            //As the terminating condition is for s3.
            // s1.pop();
            s3.pop();
        }
    }
    //Missing:
    while(!s1.empty()){
        cout<<s1.top()<<"\n";
        s1.pop();
    }
    return 0;
}
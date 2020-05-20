/*
    divide and conquer method 
    time complexity : O(n log n)
*/
#include <iostream>
#include <stack>
#include <math.h>
#include <algorithm>

using namespace std;

int max(int x, int y, int z){
    return max(max(x, y), z);
}

int minval(int *hist, int i, int j){
    if (i == -1){
        return j;
    }

    if (j == -1){
        return i;
    }

    return (hist[i] < hist[j]) ? i : j;
}

int getmid(int s, int e){
    return s + (e -s) / 2;
}

int rmqutil(int *hist, int *st, int ss, int se, int qs, int qe, int index){
    if (qs <= ss && qe >= se){
        return st[index];
    }

    if (se < qs || ss > qe){
        return -1;
    }

    int mid = getmid(ss, se);
    return minval(hist, rmqutil(hist, st, ss, mid, qs, qe, 2*index+1), rmqutil(hist, st, mid +1, se, qs, qe, 2* index+2));
}

int rmq(int *hist, int *st, int n, int qs, int qe) 
{ 
	if (qs < 0 || qe > n-1 || qs > qe) 
	{ 
		cout << "Invalid Input"; 
		return -1; 
	} 

	return rmqutil(hist, st, 0, n-1, qs, qe, 0); 
} 

int constructstutil(int hist[], int ss, int se, int *st, int si) 
{ 
	if (ss == se){
	    return (st[si] = ss);
    }     

	int mid = getmid(ss, se); 
	st[si] = minval(hist, constructstutil(hist, ss, mid, st, si*2+1), constructstutil(hist, mid+1, se, st, si*2+2)); 
	return st[si]; 
}

int *constructst(int hist[], int n) 
{ 
	int x = (int)(ceil(log2(n))); //Height of segment tree 
	int max_size = 2*(int)pow(2, x) - 1; //Maximum size of segment tree 
	int *st = new int[max_size]; 

	constructstutil(hist, 0, n-1, st, 0); 

	return st; 
} 

int getmaxarearec(int *hist, int *st, int n, int l, int r) 
{ 
	if (l > r){ 
        return INT_MIN;
    } 
	if (l == r){ 
        return hist[l]; 
    }

	int m = rmq(hist, st, n, l, r); 

	return max(getmaxarearec(hist, st, n, l, m-1), getmaxarearec(hist, st, n, m+1, r), (r-l+1)*(hist[m])); 
} 

int getmaxarea(int hist[], int n){
    int *st = constructst(hist, n);

    return getmaxarearec(hist, st, n, 0, n-1);
}

int main(){
    int hist[] = {6, 1, 5, 4, 5, 2, 6};
    int n = sizeof(hist) / sizeof(hist[0]);
    cout << "maximum area is: " << getmaxarea(hist, n);
    return 0;
}
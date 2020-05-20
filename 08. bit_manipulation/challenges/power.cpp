#include<iostream>
using namespace std;

int power(int no,int p){
	if(p==0){
		return 1;
	}
	else{
		return no*power(no,p-1);
	}
}
// power using log(p) using bitmasking the number p has log(p) bits having some set or unset
// iterating over the bits of the p and u have to increase the the number each time like this


int powerlog(int n,int p){
    int ans=1;
    while(p){   //while p>0
        if(p&1)  // if this bit is set u have to multiply
            ans*=n;
        n=n*n; //increasing the number
        p=p>>1; // shifting of p toward zero
    }
return ans;
}


int main() {
	int n,p;
	cin>>n>>p;

	cout<<powerlog(n,p);
	return 0;
}
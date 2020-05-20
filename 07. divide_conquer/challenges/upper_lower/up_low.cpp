#include<iostream>
using namespace std;

void upperbound(int s,int e,int ans,int n,int a[]){
 
 if(s>e){  // base case should be s>e
     cout<<ans<<" "<<endl;
     return;
 }
 
 int mid=(s+e)/2;
 if(a[mid]>n){
     upperbound(s,mid-1,ans,n,a); // end should be equal to mid-1
 }
 else if(a[mid]<n){
     upperbound(mid+1,e,ans,n,a);// start should be equal to mid+1
 }
 else { 
     ans=mid;
     upperbound(mid+1,e,ans,n,a);          
 }
}

void lowerbound(int s,int e,int ans,int n,int a[]){
 
 if(s>e){  // base case should be s>e
     cout<<ans<<" ";
     return;
 }

 int mid=(s+e)/2;
 if(a[mid]>n){
     lowerbound(s,mid-1,ans,n,a); // end should be equal to mid-1
 }
 else if(a[mid]<n){
     lowerbound(mid+1,e,ans,n,a); // start should be equal to mid+1
 }
 else { 
     ans=mid;
     lowerbound(s,mid-1,ans,n,a);           //lower bound     
 }
}

int main() {
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++){
    cin>>a[i];
}    
    int t;
    cin>>t;
    int b;
    for(int i=0;i<t;i++){
         cin>>b;
         lowerbound(0,n,-1,b,a);
         upperbound(0,n,-1,b,a);
    }
}
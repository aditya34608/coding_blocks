#include <bits/stdc++.h>
using namespace std;
#define ll long

bool check(ll int s,ll int e , ll int mid,ll int arr[],ll int k,ll int n){
    ll int nsum = 0;
    int no_of_people = 1;  //Initially the number of people required will be 1
    for(int h =0;h<n;h++){   //No need to update mid
        if(nsum + arr[h]<= mid){
            nsum += arr[h];

        }
        else{
            no_of_people++;
            nsum = arr[h];
            if(no_of_people>k)  //You have to check this condition here.
            return false;
            }
    }
    return true;
}

int main() {
ll int k,n;
cin>>k>>n;
ll int sum = 0;
ll int arr[1000];
ll int MAx = 0;
for(int i=0;i<n;i++){
    cin>>arr[i];
    
MAx = max(MAx,arr[i]);
}

for(int j=0;j<n;j++){
    sum += arr[j];
}

ll int s = MAx;
ll int e = sum;
ll int mid = (s+e)/2;
ll int ans=s;  //Minimum number of people required would be greater than equal to s, so intialise this value otherwise it will print garbage value if not went into while loop below.
while(s<=e){   
   mid = (s+e)/2;
    if(check(s,e,mid,arr,k,n)){
      
        ans = mid;
          e = mid - 1;
    }
    else{
        s = mid + 1;
    }
}
cout<<ans<<"\n";

}

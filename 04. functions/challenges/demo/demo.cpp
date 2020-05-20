#include <iostream>

using namespace std;

void spiralprint( int a[][],int n,int m){
int sr=0;
int er=n-1;
int sc=0;
int ec= m-1;
while(sc<=ec && sr<=er){
    for(int i=sc;i<=ec;i++){
        cout<<a[sr][i];
    }
    for(int i=sr;i<=er;i++){
        cout<<a[i][ec];
    }
    if(er>sr){
        for(int i=ec;i>=sc;i++){
            cout<<a[er][i];
        }
    }
    if(ec>sc){
        for(int i=er;i>=sr;i++){
            cout<<a[i][sc];
        }
    }
}
}

int main()
{
   int n,m;
cout<<"Enter the rows"<<endl;
cin>>n;
cout<<"Enter the columns"<<endl;
cin>>m;
int a[n][m];
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
    cin>>a[i][j];
    }
}
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
    cout<<a[i][j]<<" ";
    } cout<<endl;
}
cout<<"Spiral print is"<<endl;
spiralprint(a,n,m);
    return 0;
}

/*


#include<iostream>
using namespace std;

const int M = 2;
const int N = 2;

void print(int a[][N]){
    for(int i = 0 ; i < M ; i++){
        for(int j = 0 ; j < N ; j++)
        cout << a[i][j] <<" ";
        cout <<endl;
    }
}
int main(){
    int a[M][N];
    for(int i = 0 ; i < M ; i++){
        for(int j = 0 ; j < N ; j++)
        cin >> a[i][j] ;
    }
    print(a);
}


*/

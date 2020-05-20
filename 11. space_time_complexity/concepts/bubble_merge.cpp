#include <bits/stdc++.h>

using namespace std;

void bubblesort(int a[],int n)
{
	
	for(int i=0;i<n;i++)
		{
			for(int j=0;j<n-i-1;j++)
				{
					if(a[j]>a[j+1])
						{
							swap(a[j],a[j+1]);
						}					
				}
		}
}

int main(){
	int n;
	cin>>n;
	int a[100000];

    //create a reverse sorted array
	for(int i=0; i<n; i++){
			a[i] = n-i;
		}

    time_t start = clock();

	bubblesort(a,n);

    time_t end = clock();

    cout << "Bubble Sort " << end-start << "\n";
	
    for(int i=0; i<n; i++){
		a[i] = n-i;
    }
    start = clock();
    sort(a, a+n);
    end = clock();

    cout << "Merge Sort " << end-start << "\n";

	return 0;	
}
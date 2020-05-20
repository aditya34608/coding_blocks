#include <iostream>

using namespace std;

void series( int n1, int n2)
{
    int count = 0;
    int i = 1;
    while (count < n1){
        int num = (3*i)+2;
        i += 1;
        if ((num % n2) == 0)
        {

        }
        else{
            cout << num << endl;
            count++;
        }
    }
    
}

int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    series(n1, n2);
    return 0;
}
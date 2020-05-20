/*


Due to an immense rise in Pollution, Kejriwal is back with the Odd and Even Rule in Delhi. The scheme is as follows, each car will be allowed to run on Sunday if the sum of digits which are even is divisible by 4 or sum of digits which are odd in that number is divisible by 3. However to check every car for the above criteria can't be done by the Delhi Police. You need to help Delhi Police by finding out if a car numbered N will be allowed to run on Sunday?
Input Format

The first line contains N , then N integers follow each denoting the number of the car.

*/
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    while (n > 0){
        int no;
        cin >> no;
 
        int ans, esum, osum = 0;
        while (no > 0){
            int r = no % 10;
            if (r % 2 == 0){
                esum = esum + r;
            }
            else
            {
                osum = osum + r;            }
            
            no = no / 10;
            }
            if (esum % 4 == 0 || osum % 3 == 0){
                    cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
            }
            n -= 1; 
    }
    return 0;
}
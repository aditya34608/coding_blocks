#include <iostream>

using namespace std;
int main()
{
  int fahr, celsius;
  int min, max, step;

  cin >> min; 
  cin >> max; 
  cin >> step; 

  fahr = min;
  while(fahr <= max)
  {
//    celsius = (5.0/9.0) * fahr - 32.0; //
    celsius = (fahr - 32) * 5 / 9;
    cout <<  fahr << "\t" << celsius << endl;
    fahr = fahr + step;
}
  return 0;
}
/*
You are given an array and Q queries of two types.
Type 0: Given a number x , insert the number at the last of the array.
Type 1: Given a number X and two integers L, R, Find a number Y in the range L, R to maximize X ^ Y
Input Format

First line of the test case will be the number of queries Q . 
Then on next Q subsequent lines you will be given a query either of type 0 or type 1. Query of type 0 is of the form : 0 X, where X is the integer to be inserted . Query of type 1 is of the form : 1 L R X
Constraints

0 <= element of array <= 10^9
1 <= N <= 10^5
Output Format

For each query of type 1 output the desired value.
Sample Input

5
0 3 
0 5
0 10 
0 6 
1 1 4 6

Sample Output

10
*/

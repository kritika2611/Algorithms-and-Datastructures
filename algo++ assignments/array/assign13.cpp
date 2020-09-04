/***********************************************PRIME VISITS******************************************************
PMO gives two random numbers a & b to the Prime Minister. PM Modi wants to visit all countries between a and b
 (inclusive) , However due to shortage of time he can't visit each and every country , So PM Modi decides to 
 visit only those countries,for which country number has two divisors. So your task is to find number of countries
 Mr. Modi will visit.

Input Format:
The first line contains N , no of test cases. The next lines contain two integers a and b denoting the range of 
country numbers.

Constraints:
a<=1000000 & b<=1000000. N<=1000

Output Format
Output contains N lines each containing an answer for the test case.

Sample Input
2
1 10
11 20
Sample Output
4
4
****************************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

int main(){
    int a,b,test;
    cin>>test;
    while(test--){
        cin>>a>>b;
        int num=0;
        for(int i=a;i<=b;i++){
            //check if i is prime
            bool flag;
            flag=(i==0 || i==1)?false:true;
            for(int j=2;j<=i/2;j++){
                if(i%j==0){
                    flag=false;
                    break; 
                }    
            }
            if(flag) {
            	//cout<<i<<endl;
            	num+=1;
            }
        }
        cout<<num<<endl;

    }
    return 0;
}
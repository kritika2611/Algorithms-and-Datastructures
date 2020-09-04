/*****************************************************************************************************************
                                         CHEWBACCA AND NUMBER
Luke Skywalker gave Chewbacca an integer number x. Chewbacca isn't good at numbers but he loves inverting digits in 
them. Inverting digit t means replacing it with digit 9 - t.

Help Chewbacca to transform the initial number x to the minimum possible positive number by inverting some 
(possibly, zero) digits. The decimal representation of the final number shouldn't start with a zero.

Input Format:
The first line contains a single integer x (1 ≤ x ≤ 10^18) — the number that Luke Skywalker gave to Chewbacca.

Constraints:
x <= 100000000000000000

Output Format
Print the minimum possible positive number that Chewbacca can obtain after inverting some digits. The number 
shouldn't contain leading zeroes.

Sample Input
4545
Sample Output
4444
*****************************************************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main(){
	string num;
	cin>>num;
	int i=0;
	if (num[0]=='9')
		i++;
	for(;i<num.size();i++){
		char c;
		int a=num[i]-'0';
		int b=(a>5)?(9-a):a;
		c=b+'0';
		num[i]=c;
	}
	cout<<num;
	return 0;
}
/******************************************************************************************************************************************

Find the number of BSTs that can be formed from n nodes with labels 1,2,3,4,5.......n.
OR Find the number of Unlablled Trees that can be formed with n nodes.

INPUT: 4
OUTPUT: 14

FORMULA= 2n.C.n/(n+1)

MODIFICATIONS-  If total number of BINARY TREES is asked multipy Catalan's Number with n! 
**************************************************************************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int fact(int n){
	if(n==0 || n==1) return 1;

	int ans=1;
	while(n>=1){
        ans*=n;
        n-=1;
    }
    return ans;
}

int Using_formula(int n){
    int n2_fac=fact(2*n);
    int n_fac=fact(n);
    n_fac=n_fac*n_fac;
    return n2_fac/((n+1)*n_fac);
}

int Without_formula(int n){
    //base case
    if(n==0 || n==1) return 1;

    //recursive case
    int sum_=0;
    for(int i=1;i<=n;i++){
        int a=Without_formula(i-1);
        int b=Without_formula(n-i);
        sum_+=a*b;
    }
    return sum_;
}
int main(){
	int n;
	cin>>n;
	int ans=Using_formula(n);
	cout<<ans<<endl;

	int ans1=Without_formula(n);
	cout<<ans1<<endl;
	return 0;
}
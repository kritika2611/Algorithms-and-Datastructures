/*********************************************************************************************************************************************
														CELL MITOSIS
There's a scientist named Brook who is interested in budding of cells. He has one container which initially contains only a single cell. Now 
Brook wants n number of cells in his container. So he can change the number of cells in container in 3 different ways -:

1. Double the number of cells present in the container.

2. Increase the number of cells in the container by 1.

3. Decrease the number of cells in the container by 1.

Now, all the above operations have different costs associated with them x,y,z respectively for above operations. Help brook in finding the minimum
cost to generate n cells in the container starting from one cell .

Input Format
Each test case contains 2 lines. First lines contains an integer n Second lines contains 3 space separated integers x, y, and z

Constraints
1<=n<=10^5 1<=x<=y<=z<=10^5

Output Format
Output an integer denoting the minimum cost incurred to create n cells

Sample Input
5
2 1 3 
Sample Output
4
Explanation
Initial number of cell is 1. Applying 2nd operations four times will give 5 cells in the container , and its total cost will be 1x4 = 4. One other 
way to do is - first adding a single cell with operation 2nd ,then doubling the cells , and then again adding one more cell , with cost = 1+2+1 =4.
**************************************************************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

long long cell_mitosis(int n,int x,int y,int z){
    if(n==1) return 0;

    long long dp[100001]={0};
    dp[1]=0; //base case
    for(int i=2;i<=n;i++){
        long long op1,op2,op3;
        op1=op2=op3=INT_MAX;
        if(i%2==0) op1=x+dp[i/2];
        op2=y+dp[i-1];

        if((i+1)%2==0) op3=dp[(i+1)/2]+x+z;
        dp[i]=min(op1,min(op2,op3));
    }
    return dp[n];
}

int main() {
    int n; cin>>n;
    int x,y,z;
    cin>>x>>y>>z;
    cout<<cell_mitosis(n,x,y,z);
    return 0;
}

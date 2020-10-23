/***********************************************************************************************************************************
                                                            MIXTURES
Harry Potter has n mixtures in front of him, arranged in a row. Each mixture has one of 100 different colors (colors have numbers from 0 to 99).
He wants to mix all these mixtures together. At each step, he is going to take two mixtures that stand next to each other and mix them together, 
and put the resulting mixture in their place.
When mixing two mixtures of colors a and b, the resulting mixture will have the color (a+b) mod 100.

Also, there will be some smoke in the process. The amount of smoke generated when mixing two mixtures of colors a and b is a*b.

Find out what is the minimum amount of smoke that Harry can get when mixing all the mixtures together.

Input
There will be a number of test cases in the input.

The first line of each test case will contain n, the number of mixtures, 1 <= n <= 100.

The second line will contain n integers between 0 and 99 - the initial colors of the mixtures.

Output
For each test case, output the minimum amount of smoke.

Example
Input:
2
18 19
3
40 60 20

Output:
342
2400
In the second test case, there are two possibilities:

first mix 40 and 60 (smoke: 2400), getting 0, then mix 0 and 20 (smoke: 0); total amount of smoke is 2400
first mix 60 and 20 (smoke: 1200), getting 80, then mix 40 and 80 (smoke: 3200); total amount of smoke is 4400
The first scenario is a much better way to proceed.
**********************************************************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

long long min_smoke(int n,int colors[]){
    if(n==1) return 0;

    for(int i=1;i<n;i++) colors[i]=colors[i]+colors[i-1];
    
    long long dp[100][100];
    //base case
    for(int i=0;i<n;i++) dp[i][i]=0;

    int d=1;
    while(d<n){
        for(int i=0;i<n;i++){
            int j=i+d;
            if(j>=n) break;
            dp[i][j]=INT_MAX;
            for(int k=i;k<j;k++){
                int c1=(i==0? colors[k]:colors[k]-colors[i-1])%100;
                int c2=(colors[j]-colors[k])%100;
                long long ans=c1*c2+dp[i][k]+dp[k+1][j];
                dp[i][j]=min(dp[i][j],ans);
            }
        }
        d++;
    }
    return dp[0][n-1];
}


int main() {
    int n;
    while(scanf("%d",&n)!=EOF){
        int colors[100];
        for(int i=0;i<n;i++) cin>>colors[i];

        cout<<min_smoke(n,colors)<<endl;
    }
    return 0;
}

/******************************************************************************************************************************************
												DEFENCE KINGDOM
Theodore implements a new strategy game “Defense of a Kingdom”. On each level a player defends the Kingdom that is represented by a 
rectangular grid of cells. The player builds crossbow towers in some cells of the grid. The tower defends all the cells in the same row and 
the same column. No two towers share a row or a column.

The penalty of the position is the number of cells in the largest undefended rectangle. For example, the position shown on the picture has 
penalty 12.

Help Theodore write a program that calculates the penalty of the given position.

INPUT:
The first line of the input file contains the number of test cases.
Each test case consists of a line with three integer numbers: w — width of the grid, h — height of the grid and n — number of crossbow 
towers (1 ≤ w, h ≤ 40 000; 0 ≤ n ≤ min(w, h)).
Each of the following n lines contains two integer numbers xi and yi — the coordinates of the cell occupied by a tower 
(1 ≤ xi ≤ w; 1 ≤ yi ≤ h).

OUTPUT:
For each test case, output a single integer number — the number of cells in the largest rectangle that is not defended by the towers.


Example
Input:
1
15 8 3
3 8
11 2
8 6

Output:
12
*****************************************************************************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int l,b,n;
        cin>>l>>b>>n;

        int len_count[l+1]={0};
        int bre_count[b+1]={0};
        
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            len_count[x]+=1;
            bre_count[y]+=1;
        }

    
        //sorted vec
        vector <int> len;
        vector <int> bre;
        len.reserve(n); bre.reserve(n);

        for(int i=1;i<=l;i++){
            if(len_count[i]!=0){
                int c=len_count[i];
                while(c--) len.push_back(i);
            }
        }
        len.push_back(l+1);
        
        for(int i=1;i<=b;i++){
            if(bre_count[i]!=0){
                int c1=bre_count[i];
                while(c1--) bre.push_back(i);
            }
        }
        bre.push_back(b+1);
        

        int max_del_x=len[0]-1;
        int max_del_y=bre[0]-1;

        for(int i=1;i<n+1;i++){
            int del_x=len[i]-len[i-1]-1;
            int del_y=bre[i]-bre[i-1]-1;

            max_del_x=max(del_x,max_del_x);
            max_del_y=max(del_y,max_del_y);
        }

        int ans=max_del_x*max_del_y;
        cout<<ans<<endl;
    }
    return 0;
}

/***************************************************  IMPLEMENTING GRAPH **********************************************************************************
Given the vertices and edges of graph. create a systematic representation for each vertex.

Input format:
first line contains number of vertices and the number of edges
the following lines contain details of each edge i.e, starting point, ending point and dist.

Sample input:
5 7                                                                                                                                           
0 1 5                                                                                                                                         
1 2 3                                                                                                                                         
2 3 8                                                                                                                                         
0 3 6                                                                                                                                         
3 4 2                                                                                                                                         
2 4 10
4 1 7

Sample Output:
For vertex 0: (1,5)(3,6)                                                                                                                      
For vertex 1: (0,5)(2,3)(4,7)                                                                                                                 
For vertex 2: (1,3)(3,8)(4,10)                                                                                                                
For vertex 3: (2,8)(0,6)(4,2)                                                                                                                 
For vertex 4: (3,2)(2,10)(1,7) 
*******************************************************************************************************************************************************/

#include <iostream>
#include <list>

using namespace std;

int main(){
    int v,e;
    cin>>v;
    
    list<pair<int,int>> *l=new list<pair<int,int>>[v];
    cin>>e;
    
    while(e--){
        int s,e,dist;
        cin>>s>>e>>dist;
        l[s].push_back(make_pair(e,dist));
        l[e].push_back(make_pair(s,dist));
    }
    
    //printing the graph
    for(int i=0;i<v;i++){
        cout<<"For vertex "<<i<<": ";
        for(auto p:l[i]){
            cout<<"("<<p.first<<","<<p.second<<")";
        }
        cout<<endl;
    }
    return 0;
}


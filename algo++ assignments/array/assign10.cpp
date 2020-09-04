/***********************************************************************************************************
                                    ROTATE ARRAY ANTICLOCKWISE
*************************************************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int arr[1000][1000];
    cin>>n;
    for(int i=0; i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    //main code
    for(int j=n-1;j>=0;j--){
        for(int i=0;i<n;i++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
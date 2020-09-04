#include <iostream>
#include <climits>

using namespace std;

void s_sort(int n,int *arr){
    for(int i=0;i<n-1;i++){
        int s_loc=i;
        for(int j=i;j<n;j++){
            if(arr[j]<arr[s_loc])
                s_loc=j;
        }
        //swap
        int smallest=arr[s_loc];
        arr[s_loc]=arr[i];
        arr[i]=smallest;
    }
}

int main(){
    int n;
    cin>>n;
    int *arr=new int [n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    s_sort(n,arr);
    
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}

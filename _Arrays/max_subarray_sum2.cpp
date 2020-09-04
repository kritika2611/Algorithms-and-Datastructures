#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cout<<"enter the size of your array: ";
    cin>>n;
    
    int arr[n];
    int cumsum[n]={0};
    int current_sum=0;
    int max_sum=0;
    int right=-1;
    int left=-1;
    
        //input to array
    cout<<"enter the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //for cummulative sum
    cumsum[0]=arr[0];
    for (int i=1; i<n;i++){
        cumsum[i]=cumsum[i-1]+arr[i];
    }
    
    //finding max subarray sum
    for(int i=0; i<n; i++){
        for(int j=i; j<n;j++){
            
            current_sum=(i==0)?cumsum[j]:cumsum[j]-cumsum[i-1];
            if(current_sum>max_sum) {
                max_sum=current_sum;
                left=i;
                right=j;
            }
        }
    }
    
    //printing 
    cout<<"the maximum subarray sum is: "<<max_sum<<endl;
    cout<<"the subarray is: ";
    for (int k=left; k<=right; k++){
        cout<<arr[k]<<" ";
    }
    
    return 0;
}
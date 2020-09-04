#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	while(t--){
		int n;
		cin>>n;
		int arr[100000]={0};
		int ans=0;

		for(int i=0;i<n;i++){
			cin>>arr[i];
		}

		for(int i=0;i<n;i++){
			int left=0,right=0;
			int j=i, k=i;

			while(j>0){
				if(arr[j-1]<=arr[j]){
					left+=1;
					j--;
				}
				else 
					break;
			}

			while(k<n-1){
				if(arr[k]>=arr[k+1]){
					right+=1;
					k++;
				}
				else 
					break;
			}

			int val=max(left,right)+1;
			ans+=val;
		}
		cout<<ans<<endl;
	}
	return 0;
}
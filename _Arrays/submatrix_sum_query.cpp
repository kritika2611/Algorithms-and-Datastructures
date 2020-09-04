#include <bits/stdc++.h>
using namespace std;

void func(int r,int c,int **arr,int q,int **query){
	//forming prefix sum matrix
	for(int i=1;i<r;i++){
		for(int j=0;j<c;j++){
			arr[i][j]+=arr[i-1][j];
		}
	}
	for(int j=1;j<c;j++){
		for(int i=0;i<r;i++){
			arr[i][j]+=arr[i][j-1];
		}
	}

	for(int qi=0;qi<q;qi++){
		int ti,tj,bi,bj;
		ti=query[qi][0];
		tj=query[qi][1];
		bi=query[qi][2];
		bj=query[qi][3];

		int s1=(ti>0)?arr[ti-1][bj]:0;
		int s2=(tj>0)?arr[bi][tj-1]:0;
		int s3=(ti>0 && tj>0)?arr[ti-1][tj-1]:0;
		int ans=arr[bi][bj]-s1-s2+s3;
		cout<<ans<<endl;
	}
}

int main(){
	int r,c;
	cin>>r>>c;
	//defining array
	int **arr=new int *[r];
	for(int i=0;i<r;i++){
		arr[i]=new int [c];
	}
	//input in array
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>arr[i][j];
		}
	}
	//defining query points
	int q;
	cin>>q;
	int **query=new int *[q];
	for(int i=0;i<q;i++){
		query[i]=new int [4];
	}
	//input to query point
	for(int i=0;i<q;i++){
		for(int j=0;j<4;j++){
			cin>>query[i][j];
		}
	}
	func(r,c,arr,q,query);

	return 0;
}
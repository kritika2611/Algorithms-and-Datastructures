#include <bits/stdc++.h>

using namespace std;

int *func(int r,int c,int ** arr){
	//sum of submatrix
	int ans=0;
	for(int i=1;i<r;i++){
		for(int j=0;j<c;j++){
			arr[i][j]=arr[i][j]+arr[i-1][j];
		}
	}
	for(int j=1;j<c;j++){
		for(int i=0;i<r;i++){
			arr[i][j]=arr[i][j]+arr[i][j-1];
		}
	}

	int * ab=new int[c];
	ab=arr[1];
	int a1,a2,b;
	for(int ti=0;ti<r;ti++){
		for(int tj=0;tj<c;tj++){
			for(int bi=ti;bi<r;bi++){
				for(int bj=tj;bj<c;bj++){
					a1=(tj>=1)?arr[bj][tj-1]:0;
					a2=(ti>=1)?arr[ti-1][bj]:0;
					b=(ti>=1 && tj>=1)?arr[ti-1][tj-1]:0;
					ans+=arr[bi][bj]-a1-a2+b;
				}
			}
		}
	}
	cout<<ans<<endl;
	return ab;
}

int main(){
	int n,m;
	cout<<"enter number of rows and columns: ";
	cin>>n>>m;
	
	int **arr;
	arr=new int*[n];
	for(int i=0;i<n;i++){
		arr[i]=new int[m];
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}

	int *ab=func(n,m,arr);
	for(int i=0;i<m;i++){
		cout<<ab[i]<<" ";
	}

	for(int i=0;i<n;i++){
		delete [] arr[i];
	}
	delete [] arr;
	return 0;
}
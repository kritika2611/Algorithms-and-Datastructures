#include <bits/stdc++.h>

using namespace std;

int min_cost(int cost[],int n,int m,int rick[],int cab[]){
	int rick_cost=0,cab_cost=0;
	int ans=0;

	for(int i=0;i<n;i++){
		rick_cost+=min(rick[i]*cost[0],cost[1]);
	}
	rick_cost=min(rick_cost,cost[2]);

	for (int i=0;i<m;i++){
		cab_cost+=min(cab[i]*cost[0],cost[1]);
	}
	cab_cost=min(cab_cost,cost[2]);
	ans=min(cab_cost+rick_cost,cost[3]);
	return ans;

}


int main(){
	int test;
	cin>>test;

	int n,m,ans;
	int cost[4],rick[1000],cab[1000];
	while(test--){
		for(int i=0;i<4;i++){
			cin>>cost[i];
		}
		cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>rick[i];
		}
		for(int i=0;i<m;i++){
			cin>>cab[i];
		}
		ans=min_cost(cost,n,m,rick,cab);
		cout<<ans<<endl;
	
	}
	return 0;
}
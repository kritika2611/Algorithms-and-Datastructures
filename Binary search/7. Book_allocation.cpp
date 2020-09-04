/***********************************************    BOOK ALLOCATION   *****************************************************************************
You are given number of pages in n different books and m students. The books are arranged in ascending order of number of pages. Every student is 
assigned to read some consecutive books. The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum.

Input Format
First line contains integer t as number of test cases. Next t lines contains two lines. For each test case, 1st line contains two integers n and m 
which represents the number of books and students and 2nd line contains n space separated integers which represents the number of pages of n books 
in ascending order.

Constraints
1 < t < 50
1< n < 100
1< m <= 50
1 <= Ai <= 1000

Output Format
Print the maximum number of pages that can be assigned to students.

Sample Input
1
4 2
12 34 67 90
Sample Output
113 
**********************************************************************************************************************************************/

#include <bits/stdc++.h>

using namespace std;

bool feasibility(int n,int m,int *pages,int max_pages){
	int l=0;
	int i;
	for(i=1;i<=m;i++){
		int pages_read=0;
		
		while(l<n){
			pages_read+=pages[l];
			if(pages_read<=max_pages)
				l++;
			else
				break;
		}
	}
	if(l==n)
		return true;
	else
		return false;
}

int main(){
	int t;
	cin>>t;

	while(t--){
		int n,m;
		cin>>n>>m;
		
		int sum_pages=0;
		int *pages=new int[n];
		for(int i=0;i<n;i++){
			cin>>pages[i];
			sum_pages+=pages[i];
		}

		//binary search
		int s=pages[n-1];
		int e=sum_pages;
		int ans=-1;
		while(s<=e){
			int mid=(s+e)/2;
			bool feas=feasibility(n,m,pages,mid);
			if(feas){
				e=mid-1;
				if(ans==-1 || mid<ans)
					ans=mid;
			}
			else
				s=mid+1;
		}
		cout<<ans<<endl;

		delete [] pages;
	}


	return 0;
}
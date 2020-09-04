/********************************************************  PLACE TILES  *************************************************************************
Given a “4 x n” board and tiles of size “4 x 1” AND "1 x 4", count the number of ways to tile the given board using the tiles. A tile can either 
be placed horizontally i.e., as a 1 x 4 tile or vertically i.e., as 4 x 1 tile.

************************************************************************************************************************************************/



#include <bits/stdc++.h>

using namespace std;

int place_titles(int n){
	//base case
	if(n<4)
		return 1;

	int x=place_titles(n-1);
	int y=place_titles(n-4);
	return x+y;

}

int main(){
	int n;
	cin>>n;

	//board size 4 x n
	cout<<place_titles(n);


	return 0;
}
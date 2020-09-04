#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>

using namespace std;


class car{
public:
	string car_name;
	int x,y;

	car(){

	}
	car(string s,int x,int y){
		car_name=s;
		this->x=x;
		this->y=y;
	}

	int dist(){
		return x*x+y*y;
	}
};

bool comp(car c1,car c2){
	int d1=c1.dist();
	int d2=c2.dist();
	if(d1==d2)
		return c1.car_name<c2.car_name;

	return d1<d2;
}

int main(){
	int n;
	cin>>n;

	vector<car> v;
	while(n--){
		string name;
		int x,y;
		cin>>name>>x>>y;
		car temp(name,x,y);
		v.push_back(temp);
	}

	sort(v.begin(),v.end(),comp);

	for(auto c:v){
		cout<<"Car: "<<c.car_name<<" distance: "<<c.dist()<<endl;
	}
}
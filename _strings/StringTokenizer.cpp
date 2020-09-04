#include <bits/stdc++.h>
using namespace std;

void staticfun(int a){
	static int b=a;
	cout<<b<<endl;
	b++;
}



int main()
{
	int a=5;
	staticfun(a);
	staticfun(2);
	return 0;
}
    
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int x,y,t;
	cin>>t;
	while(t--){
	    int r=11;
		int a=0,b=0;
		int flag = 0;
		int teamA = 0,teamB = 0;
		cin>>x>>y;
		if(x>y){
			teamA = 1;
		} else {
			teamB = 1;	
		}
		while(r--){
			int z;
			cin>>z;
			if(z%2 == 1){
				a++;
			}
		}
		r=11;
		while(r--){
			int z;
			cin>>z;
			if(z%2 == 1){
				b++;
			}
		}
		if(b>a && teamA == 1 || a>b && teamB == 1){
			cout<<"chef"<<endl;
		} else {
			cout<<"alan"<<endl;
		}
		
	}
	return 0;
}
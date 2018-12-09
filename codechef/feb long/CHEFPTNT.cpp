#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
	    int flag = 0;
		int odd=0,even=0,oddmonth,evenmonth;
		int n,m,x,k;
		cin>>n>>m>>x>>k;
		string s;
		cin>>s;
		for(int i=0;i<s.length();i++){
			if(s[i] == 'E') {
				even += 1;
			} else {
				odd += 1;
			}
		}
		if(m%2 == 0){
			oddmonth = m/2;
			evenmonth = m/2;
		} else {
			evenmonth = m/2;
			oddmonth = evenmonth + 1;
		}
		
			if(oddmonth*x + evenmonth*x >= n){
				cout<<"yes"<<endl;
			} else {
				cout<<"no"<<endl;
			}
		
	}
	return 0;
}
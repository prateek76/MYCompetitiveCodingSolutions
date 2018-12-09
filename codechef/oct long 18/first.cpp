#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
		long long int p1,p2,k;
		cin>>p1>>p2>>k;
		long long int total = p1 + p2;
		if(total % (2*k) == 0) {
			cout<<"CHEF"<<endl;
		} else if(total % (k) == 0 && total%(2*k) != 0) {
			cout<<"COOK"<<endl;
		} else if(total%(2*k) < k && total%k < k) {
			cout<<"CHEF"<<endl;
		} else {
			cout<<"COOK"<<endl;
		}
 	}
	return 0;
}
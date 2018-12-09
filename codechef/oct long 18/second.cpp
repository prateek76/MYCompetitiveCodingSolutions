#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
		long long int n;
		long long int one = 1,two = 0,three = 0;
		cin>>n;
		n--;
		long long int cnt = 1;
		if(n/26 > 0) {
			long long int laplace = n/26;
			n -= (laplace*26);
			cnt = pow(2,laplace);
			one = cnt;
		//	cout<<one<<"one"<<endl;
			two = 0;
			three = 0;
		}

		if(n/10 > 0) {
			n -= 10;
			three = cnt;
		//	cout<<three<<"three"<<endl;
			two = 0;
			one = 0;
		}
//	cout<<cnt<<"cnt"<<endl;
		if(n/2 > 0) {
			if(one > 0) {two = cnt;
		//	cout<<two<<"two"<<endl;
			one = 0;
			three = 0;
			}
		}
		
		cout<<one<<" "<<two<<" "<<three<<endl;
 	}
	return 0;
}
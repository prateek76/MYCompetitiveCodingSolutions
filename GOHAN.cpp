#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin>>t;
	while( t-- ) {
		long double r,l,c,v;
		cin>>r>>l>>c>>v;
		long double _fac = (-r/(2*l)); 
		//long double _num = (r*r*l*c) - (2*r*r*c*l) +(4*l*l);
		//long double _den = ( 4*l*l );
		long double ans = 1 + ((_fac*_fac)*l*c) + (r*c*(_fac)); 
		cout<<setprecision(20)<<ans<<endl;
	}
	return 0;
}
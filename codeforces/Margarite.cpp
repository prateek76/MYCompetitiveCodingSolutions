#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--) {
		long long int l,r;
		long long int ans = 0;
		cin>>l>>r;
		if(l%2 == 1) {
			if((r-l)%2 == 0) {
				ans = (r-l)/2 + (-1*r);
			} else {
				ans = (r-l)/2;
			}
		} else {
			if((r-l)%2 == 0) {
				ans = ((-1)*((r-l)/2)) + r;
			} else {
				ans = -1*((r-l)/2);
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}
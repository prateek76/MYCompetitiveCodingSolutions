#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
		long long int n,q;
		cin>>n>>q;
		long long int arr[100006];
		for(int i=1;i<=n;i++) {
			cin>>arr[i];
		}
		while(q--) {
			long long int ans_cnt=0;
			
			int a,b;
			cin>>a>>b;
			long long int anser;
			for(int i=a;i<=b;i++) {
				int cnt=0;
				for(int j=i;j<=b;j++) {
				if(cnt == 0) {
					anser = arr[i];		
				} else {
					anser = (anser & arr[j]);
				}
				cnt++;
				long double they = sqrt(anser);
				long long int we = sqrt(anser);
				if(they == we) ans_cnt++;

				}
				
			}
			cout<<ans_cnt<<endl;
			
		} 
	}
	return 0;
}
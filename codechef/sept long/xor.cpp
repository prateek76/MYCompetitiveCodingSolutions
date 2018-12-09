#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
		map<long long int,long long int> odd,even;
		long long int n;
		cin>>n;
		long long int oddCnt = 0,evenCnt = 0;
		for(int i=0;i<n;i++) {
			int arr;
			cin>>arr;
			if(arr % 2 == 0) {
				even[arr]++;
				evenCnt++;
			} else {
				odd[arr]++;
				oddCnt++;
			}
		}

		long long int cnt = (evenCnt*(evenCnt-1))/2 + (oddCnt*(oddCnt-1))/2;

		for(auto i=odd.begin();i != odd.end();) {
			
			if((*i).second > 1) {
				cnt -= ((((*i).second)*(((*i).second)-1))/2);
			}
			auto I = i++;
			
			if(i != odd.end()) {
				if(((*i).first^(*I).first) == 2) {
					cnt -= ((*i).second*(*I).second);
				}
			}
		}

		for(auto i=even.begin();i != even.end();) {

			if((*i).second > 1) {
				cnt -= ((((*i).second)*(((*i).second)-1))/2);
			}
			auto I = i++;
			
			if(i != even.end()) {
				if(((*i).first^(*I).first) == 2) {
					cnt -= ((*i).second*(*I).second);
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
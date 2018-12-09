#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
		priority_queue<int> motu;
		priority_queue<int, vector<int>, greater<>> tomu;
		int n,k;
		cin>>n>>k;
		int cnt = 0;
		int motu_sum = 0;
		int motu_new = 0;
		int tomu_sum = 0;
		int tomu_new = 0;
		while(n--) {
			int temp;
			cin>>temp;
			if(cnt%2 == 0) {
				motu.push(temp);
				motu_sum += temp;
			} else if(cnt%2 == 1) {
				tomu.push(temp);
				tomu_sum += temp;
			}
			cnt++;
		}
		int flag = 0;
		if(tomu_sum > motu_sum)
			flag = 1;
		else {
		    while(k--){
				int z = motu.top();
				int y = tomu.top();
				tomu_new += z - y;
				motu_new += y - z;
				motu.pop();
				tomu.pop();
				motu.push(y);
				tomu.push(z);
			
		    }
		    if(( tomu_sum+tomu_new ) > ( motu_sum+motu_new )) {
				flag = 1;
			}
		}
		
		if(flag == 0)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
		
		
		
		
	}
	return 0;
}
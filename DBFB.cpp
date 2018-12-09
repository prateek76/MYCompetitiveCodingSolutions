#include<bits/stdc++.h>

using namespace std;
int mod = 1000000007;

int main()
{
	int t;
	cin>>t;
	while(t--) {
		int n,m;
		vector<int> A_con;
		vector<int> B_con;
		long long int arr[1000006];
		cin>>n>>m;
		int m_copy = m;
		int M = m;
		while(m--){
			int temp;
			cin>>temp;
			A_con.push_back(temp);
		}
		while(m_copy--){
			int temp;
			cin>>temp;
			B_con.push_back(temp);
		}
		long long int result = 0;
		for(int i=0;i<M;i++){
			for(int j=0;j<M;j++){
				arr[1] = A_con[i];
				arr[j] = B_con[j];
				
				for(int ii=3;ii<=n;ii++){
					arr[ii] = ((arr[ii-1])%mod + (arr[ii-2])%mod)%mod;
				}
				result = ((result)%mod + (arr[n])%mod)%mod;
			}
		}
		cout<<result<<endl;
	}
	return 0;
}
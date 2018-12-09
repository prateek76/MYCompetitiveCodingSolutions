#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	int arr[1006][1006]; 
	while( t-- ) {
		priority_queue<int> q;
		int n,m;
		cin>>n>>m;
		for(int i=1; i<= n; i++) {
			for(int j=1; j <= m; j++) {
				cin>>arr[i][j];
			}
		}
		for(int i=2;i<n;i++){
			int tmpsum = 0;
			int tmptmpsem = 0;
			int ramos;
			for(int j=2;j<m;j++) {
				tmpsum = arr[i][j] + arr[i-1][j] + arr[i+1][j] + arr[i][j-1] + arr[i][j+1];
				
				if(i-2 > 0) {
					tmptmpsem = arr[i-2][j];
					ramos = 0;
					for(int lol = i-2;lol>=1;lol--) {
						ramos += arr[lol][j];
						if(ramos > tmptmpsem) {
							tmptmpsem = ramos;
						}
					}
				}
				if(tmptmpsem > 0)
				tmpsum += tmptmpsem;
				
				
				if(i+2 < n+1) {
					tmptmpsem = arr[i+2][j];
					ramos = 0;
					for(int lol = i+2;lol<=n;lol++) {
						ramos += arr[lol][j];
						if(ramos > tmptmpsem) {
							tmptmpsem = ramos;
						}
					}
				}
				if(tmptmpsem > 0)
				tmpsum += tmptmpsem;
				
				
				if(j-2 > 0) {
					tmptmpsem = arr[i][j-2];
					ramos = 0;
					for(int lol = j-2;lol>=1;lol--) {
						ramos += arr[i][lol];
						if(ramos > tmptmpsem) {
							tmptmpsem = ramos;
						}
					}
				}
				if(tmptmpsem > 0)
				tmpsum += tmptmpsem;
				
				
				if(j+2 < m+1) {
					tmptmpsem = arr[i][j+2];
					ramos = 0;
					for(int lol = j+2;lol<=m;lol++) {
						ramos += arr[i][lol];
						if(ramos > tmptmpsem) {
							tmptmpsem = ramos;
						}
					}
				}
				if(tmptmpsem > 0)
				tmpsum += tmptmpsem;
				q.push(tmpsum);
				
			}
		}
		cout<<q.top()<<endl;
	}
	return 0;
}
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	int n,u,d;
	int arr[109];
	while(t--){
		cin>>n>>u>>d;
		for(int i=1;i<=n;i++){
			cin>>arr[i];
		}
		int flag = 1;
		int cnt = 0;
		for(int i=2;i<=n;i++){
			if(arr[i]>arr[i-1]){
				if(abs(arr[i]-arr[i-1]) <= u){
					cnt++;
				} else {
					break;
				}
			}
			else if(arr[i]<arr[i-1]){
				if(abs(arr[i]-arr[i-1])<=d){
					cnt++;
				} else {
					if(flag == 1){
					flag = 0;
					cnt++;
					} else {
						break;
					}
				}
			}
		
		}
		cout<<cnt<<endl;
	}
	return 0;
}
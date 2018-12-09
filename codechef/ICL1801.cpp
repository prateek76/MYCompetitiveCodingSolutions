#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int t;
	int n,m;
	cin>>t;
	while(t--){
		int arr[100000];
		cin>>n>>m;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>arr[j];
			}
		}
		int sum_cyb = 0;
		int su_sur = 0;
		sort(arr,arr+(n*m),greater<int>());
		for(int i=0;i<((n*m)-1;i++){
			if(i%2 == 0){
				sum_cyb += arr[i];
			} else {
				su_sur += arr[i];
			}
		}
		if(su_sur == sum_cyb){
			cout<<"Draw"<<endl;
		}
		else if(su_sur > sum_cyb){
			cout<<"Geno"<<endl;
		} else {
			cout<<"Cyborg"<<endl;
		}
	}
	return 0;
}
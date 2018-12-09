#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[1000009];
	int pre_ans[1000009]={0};
	set<int> se;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		se.insert(arr[i]);
		
	}
	return 0;
}
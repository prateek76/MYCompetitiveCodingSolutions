#include <bits/stdc++.h>
using namespace std;

int main() {
	long long int n,m;
	cin>>n>>m;
	
	priority_queue<pair<long long int,long long int> > pq; 
	long long int arr[100006];
	for(long long int i=0;i<n;i++) {
		cin>>arr[i];
	}
	
	for(long long int i = 0; i < n; i++) {
		long long int temp;
		cin>>temp;
		pq.push(make_pair(arr[i]*temp,arr[i]));
	}
	
	for(long long int i=0;i<m;i++) {
		pair<long long int,long long int> top = pq.top();
		if(top.first <= 0) break;
		long long int change1 = top.first;
		long long int change2 = top.second;
		change1 = change1 - change2;
		//if(change1 < 0) change1 = 0;
		//cout<<top.first<<endl;
		pq.pop();
		pq.push(make_pair(change1,change2));
	}
	
	pair<long long int, long long int> top = pq.top();
	cout<<top.first;
	return 0;
}

//////////////////////////
/////////////////////////
///// 27 Points/////////
///////////////////////
//////////////////////
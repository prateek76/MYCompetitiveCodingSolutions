#include <bits/stdc++.h>
using namespace std;

bool sortinrev(const pair<long long int,long long int> &a, const pair<long long int,long long int> &b) { 
       return (a.first > b.first); 
} 

int main() {
	long long int n,m;
	cin>>n>>m;
	
	vector<pair<long long int,long long int>> vec;
	
	for(long long int i=0;i<n;i++) {
		long long int temp;
		cin>>temp;
		vec.push_back(make_pair(-1,temp));
	}
	
	for(auto i = vec.begin(); i != vec.end(); i++) {
		long long int temp;
		cin>>temp;
		(*i).first = (*i).second*temp;
	}
	sort(vec.begin(),vec.end(),sortinrev);
	for(long long int i=0;i<m;i++) {
		vec[0].first = vec[0].first - vec[0].second;
		sort(vec.begin(),vec.end(),sortinrev);
	}
	cout<<vec[0].first;
	return 0;
}
#include<bits/stdc++.h>

using namespace std;

long long int disTanceM(int x1,int x2,int y1,int y2,int r1,int r2) {
	long long int check = sqrt(((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2)));
	return check;
}

int disTance(int x1,int x2,int y1,int y2,int r1,int r2) {
	long long int check = sqrt(((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2)));
	if(check <= (r1+r2)) {
		return 2;
	} else if(check > (r1+r2)) {
		return 3;
	}
}

int main() {
	int n,q;
	cin>>n>>q;
	vector<pair<pair<int,int>,int>> vec;
	for(int i=0;i<n;i++) {
		int a,b,r;
		cin>>a>>b>>r;
		vec.push_back(make_pair(make_pair(a,b),r));
	}
	while(q--) {
		int temp;
		cin>>temp;
		int cnt=0;
		for(int i=0;i < vec.size();i++) {
			for(int j=0;j < vec.size();j++) {
					if(i == j) continue;
					if(vec[i].first.first == vec[j].first.first && vec[i].first.second == vec[j].first.second) {
						if(temp == abs(vec[i].second - vec[j].second)) {
							//cout<<"eq"<<endl;
							cnt++;
						}
					} else if(disTance(vec[i].first.first,vec[j].first.first,vec[i].first.second,vec[j].first.second,vec[i].second,vec[j].second) == 2) {
						if(temp >= 0 && temp <= (disTanceM(vec[i].first.first,vec[j].first.first,vec[i].first.second,vec[j].first.second,vec[i].second,vec[j].second)+vec[i].second+vec[j].second)) {
							//cout<<"int"<<endl;
							cnt++;
						}
					} else if(disTance(vec[i].first.first,vec[j].first.first,vec[i].first.second,vec[j].first.second,vec[i].second,vec[j].second) == 3) {
						if(temp >= abs((disTanceM(vec[i].first.first,vec[j].first.first,vec[i].first.second,vec[j].first.second,vec[i].second,vec[j].second)+vec[i].second+vec[j].second)-vec[i].second-vec[j].second) && temp <= (disTanceM(vec[i].first.first,vec[j].first.first,vec[i].first.second,vec[j].first.second,vec[i].second,vec[j].second)+vec[i].second+vec[j].second)) {
							//cout<<"dur"<<endl;
							cnt++;
						}
					}
				
			}
		}
		cout<<cnt/2<<endl;
	}
	return 0;
}
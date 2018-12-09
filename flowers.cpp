#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,m;
	int arrO[2009][2009];
	map<int,int> mapy;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			cin>>arrO[i][j];
			mapy[arrO[i][j]]++;
		}
	}
	int maxoans = 0;
	vector<int> vec;
	for(auto lt=mapy.begin(); lt != mapy.end(); lt++) {
		if((*lt).second > 0)
			vec.push_back((*lt).first);
	}
	
	for(int i=0;i<vec.size();i++) {
		for(int j=0;j<vec.size();j++){
			if(i != j) {
				int arr[2006][2006];
				for(int ii=1;ii<=n;ii++) {
					for(int jj=1;jj<=m;jj++) {
						arr[ii][jj] = arrO[ii][jj];	
					}
				}
				for(int hh=0;hh<n;hh++) {
					arr[hh][0] = 0;
				}
				for(int hh=0;hh<m;hh++) {
					arr[0][hh] = 0;
				}
	

	for(int ii=1;ii<=n;ii++) {
		for(int jj=1;jj<=m;jj++) {
			if(arr[ii][jj] == vec[i] || arr[ii][jj] == vec[j]) {
				arr[ii][jj] = 0;
			}
		}
	}
	
	map<int,int> osama;
	int index = -55;
	set<int>vd;
	for(int ii=1;ii<=n;ii++) {
		for(int jj=1;jj<=m;jj++) {
			if( arr[ii][jj] == 0 ) {
				if((arr[ii-1][jj] < 0) && (arr[ii][jj-1] < 0)) {
					if((arr[ii-1][jj] != arr[ii][jj-1])) {
						if(osama[arr[ii-1][jj]] >= osama[arr[ii][jj-1]]) {
						arr[ii][jj] = arr[ii-1][jj];
						} else {
						arr[ii][jj] = arr[ii][j-1];
						}
						osama[arr[ii][jj]]++;
						//osama[arr[ii][jj]] += osama[arr[ii-1][jj]];
						if(osama[arr[ii-1][jj]] >= osama[arr[ii][jj-1]]) {
						vd.insert(arr[ii][jj-1]);
						} else {
						vd.insert(arr[ii-1][jj]);
						}
						continue;
					}
				}
				if(arr[ii-1][jj] < 0) {
					arr[ii][jj] = arr[ii-1][jj];
					osama[arr[ii][jj]]++;
					if(arr[ii-1][jj-1] > 0) {
						//vd.insert(arr[ii-1][jj-1]);
					}
					continue;
				} if(arr[ii][jj-1] < 0) {
					arr[ii][jj] = arr[ii][jj-1];
					osama[arr[ii][jj]]++;
					continue;
				} else {
					index--;
					osama[index]++;
					arr[ii][jj] = index;
				}
			}
		}
	}
	
	int maxomum = 0;
	for(auto it = osama.begin(); it != osama.end(); it++) {
		if((*it).second > maxomum) {
			maxomum = (*it).second;
		}
	}
	set<int>:: iterator uit;
	for(uit=vd.begin();uit!=vd.end();uit++) {
			maxomum += osama[(*uit)];
	}
	
	if(maxomum > maxoans) {
		maxoans = maxomum;
	}
			}	
		}
	}
	cout<<maxoans;
	return 0;
}
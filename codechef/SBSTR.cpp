#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		string s;
		int k;
		cin>>s>>k;
		int glbcnt = 0;
		for(int i=0;i<s.length();i++) {
			map<char,int> tmpmap;
			set<char> tmpset;
			for(int j=i+tmpset.size();j<s.length();j++){
				int flg = 0;
				tmpset.insert(s[j]);
				tmpmap[s[j]]++;
				int tempocnt = 0;
				int store;
				for(auto it = tmpmap.begin();it != tmpmap.end();it++) {
					if(tempocnt == 0) {
						store = (*it).second;	
						tempocnt++;
					} else {
						if((*it).second != store) {
							flg = 1;
						}
					}
				}
				if(flg == 0 && tmpset.size() >= k) {
					glbcnt++;
				}
			}
		}
		cout<<glbcnt<<endl;
	}
	
}
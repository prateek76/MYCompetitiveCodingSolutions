#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int t;
	cin>>t;
	int n;
	while(t--){
		int ans = -1;
		cin>>n;
		map<int, pair<string,string>> m;
		while(n--){
			int x;
			string s1,s2;
			cin>>x;
			cin>>s1>>s2;
			m[x] = make_pair(s1,s2);
		}
		int flag = 0;
		for(auto it = m.begin(); it != m.end(); it++){
		     
			for(auto i = it;i != m.end(); i++){
				if((*it).first != (*i).first){
				    //cout<<(*i).second.second<<" "<<(*i).second.first<<" "<<(*i).first<<endl;
					if((*it).second.second == (*i).second.second){
						ans = 1;
						
						if((*it).second.second == (*i).second.second && (*it).second.first != (*i).second.first){
							ans = 2;
							flag  = 1;
							break;
						}
					}
				}
			}
				if(flag == 1){
			        break;
				}
		}
		cout<<ans<<endl;
		}
		
	
	return 0;
}
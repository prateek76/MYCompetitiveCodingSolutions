#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t,n,k;
	int arrk[100006],arrv[100006],arrOPT[100006];
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=0;i<n;i++){
			cin>>arrk[i];
		}
		for(int i=0;i<n;i++){
			cin>>arrv[i];
		}
		for(int i=0;i<k;i++){
			cin>>arrOPT[i];
		}
		map<int,int> mapy;
		for(int i=0;i<n;i++){
			mapy[arrk[i]] = arrv[i];
		}
		int cnt=0;
		for(int i=0;i<k;i++){
			cnt++;
			if(cnt%2 == 0){
			for(auto it = mapy.rbegin();it != mapy.rend();it++){
				if(arrOPT[i]>(*it).second){
					
				} else {
					mapy[(*it).first] = arrOPT[i];
					++it;
					mapy.erase(it, mapy.end());
				}
			}
		} else {
			for(auto it = mapy.begin();it != mapy.end();it++){
				if(arrOPT[i]>(*it).second){
					
				} else {
					mapy[(*it).first] = arrOPT[i];
					++it;
					mapy.erase(it, mapy.end());
				}
			}
		}
		}
		int sum=0;
		for(auto it = mapy.begin();it != mapy.end();it++){
				sum += ((*it).first)*((*it).second);
			}
			cout<<sum<<endl;
	}
	return 0;
}
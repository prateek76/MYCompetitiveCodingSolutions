#include<bits/stdc++.h>

using namespace std;

int arrr[1000009]={0};

void sieve(int n){
	arrr[0] = 1;
	arrr[1] = 1;
	for(int i=2;i*i<=n;i++){
		if(arrr[i] == 0){
			for(int j=2*i;j<=n;j+=i){
				arrr[j] = 1;
			}
		}
	}
}

int main(){
	int t;
	cin>>t;
	sieve(1000009);
	while(t--){
		int glo = 0,onecnt = 0;
		map<int,int> m;
		map<int,int>::iterator it;
		int n;
		cin>>n;
		int arr[10009];
		for(int i=0;i<n;i++){
			cin>>arr[i];
			if(arr[i] == 1){
				onecnt++;
			}
		}
		for(int i=0;i<n;i++){
			if(arrr[arr[i]] == 0){
				m[arr[i]]++;
				continue;
			}
			int x = sqrt(arr[i]);
			float y = sqrt(arr[i]);
			if(x == y){
				if(arrr[x] == 0 && onecnt > 0){
						glo++;
						onecnt--;
				}
			}
		}
		
		for(it = m.begin();it !=m.end();++it){
			glo += ((*it).second/2);
		}		

		if(glo%2 == 0){
			cout<<"Shivam"<<endl;
		} else {
			cout<<"Sagar"<<endl;
		}
	}
	return 0;
}
#include<bits/stdc++.h>

using namespace std;

long long int  calculate(long long int sum,long long int cha,long long int num,long long int k){
	long long int  x = (cha - num+(sum/k));
	return x;
}

int main(){
	
	long long int  t;
	cin>>t;
	while(t--){
		long long int  n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		sort(s.begin(), s.end(), greater<char>());
		long long int max_power = n;
		long long int sum = 0;
		long long int cha_len = n;
		long long int num = 0;
		for(long long int  i=0;i<n;i++){
			sum += (s[i]-96);
			cha_len--;
			num++;
			long long int z = calculate(sum,cha_len,num,k);
			//cout<<sum<<" ";
			if(z>max_power){
				max_power = z;
			}
		}
		
		cout<<max_power<<" "<<1<<endl;
	}
	return 0;
}
#include<bits/stdc++.h>

using namespace std;

int factorial(int n)
{
    if (n == 0 || n == 1)
      return 1;
    return n*factorial(n-1);
}

int main(){
	int t;
	cin>>t;
	int mm = 1000000007 ;
	while(t--){
		int n;
		cin>>n;
		map<string,int> m;
		map<string,int>::iterator it;
		string s;
		while(n--){
			cin>>s;
			m[s]++;
		}
		long long int ans = 1;
		long long int temp;
		long long int sum = 0;
		for(it = m.begin();it!=m.end();it++){
			temp = (*it).second);
			while(temp > 0){
				long long int x = factorial(temp);
				temp--;
				sum = ((sum%mm)+(x%mm))%mm;
			}
			ans = ((ans)%mm * (sum)%mm)%mm;
		}
		cout<<ans<<endl;
	}
	return 0;
}
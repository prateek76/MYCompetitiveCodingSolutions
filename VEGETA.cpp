#include<bits/stdc++.h>

using namespace std;

const long long int MAX_SIZE= 1000006;

int least_prime[MAX_SIZE] = {0};

void sieve( int n ) {
	least_prime[1] = 1;
	//least_prime[2] = 2;
	for(int i=2;i<=MAX_SIZE;i++) {
		if(least_prime[i] == 0) {
			least_prime[i] = i;
			
			for( int j = 2*i; j <= n; j += i ) {
				if(least_prime[j] == 0) {
					least_prime[j] = i;
 				}
			}
		}
	}
}

int preCum[MAX_SIZE] = {0};

int All_primeFactors( int n ) {
	set<int> sety;
	while(n != 1) {
		sety.insert(least_prime[n]);
		n /= least_prime[n];
	}
	return sety.size();
}

int main() {
	sieve(MAX_SIZE);
	int t;
	cin>>t;
	while( t-- ) {
		int n,m;
		cin>>n>>m;
		int ans = 0;
		for(int i=n;i<m;i++) {
			ans += All_primeFactors(i);
		}
		cout<<ans<<endl;
	}
	return 0;
}
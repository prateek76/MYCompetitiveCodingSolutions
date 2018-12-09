#include<bits/stdc++.h>

using namespace std;

long long int Com(long long int n, int r) {
	if (r > n / 2) r = n - r;
	long long ans = 1;
	int i;

	for (i = 1; i <= r; i++) {
		ans *= n - r + i;
		ans /= i;
	}

	return ans;
}

int main() {

	int n;
	cin >> n;
	map<long long int, long long int> m;
	map<long long int, long long int> ::iterator it;
	for (int i = 0;i < n;i++) {
		long long int key;
		//long long int value;
		cin >> key;
		m[key]++;
	}
	long long int sum = 0;
	if (n == 1) {
		cout << 0;
		exit(0);
	}
	for (it = m.begin();it != m.end();it++) {
		//cout<<(*it).second;
		if ((*it).second == 1)
			continue;
		sum += Com((*it).second, 2);
	}
	cout << sum;
	//cout<<(Com(5,2));
	return 0;
}

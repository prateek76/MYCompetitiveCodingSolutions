#include<bits/stdc++.h>

using namespace std;

int prime[2000006] = { 0 };

void sieve(int n) {
	prime[0] = 1;
	prime[1] = 1;
	for (int i = 2;i*i <= n;i++) {
		if (prime[i] == 0) {
			for (int j = 2 * i; j <= n; j += i) {
				prime[j] = 1;
			}
		}
	}
}

int main()
{
	list<int> LI;
	list<int>::iterator it;
	int n;
	int x;
	cin >> n;
	sieve(2000006);
	for (int i = 0;i < n;i++) {
		cin >> x;
		if (prime[x] == 0) {
			LI.push_back(x);
		}
	}
	LI.sort();
	int ans = LI.back() - LI.front();
	if (LI.empty()) {
		cout << -1;
	}
	else {
		cout << ans;
	}

	return 0;
}
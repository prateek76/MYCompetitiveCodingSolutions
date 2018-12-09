#include<bits/stdc++.h>

using namespace std;

long long int ans(int a, int b, int c, long long k) {
	for (int i = 0;i < 1000006;i++) {
		if (a*i*i + b * i + c >= k) {
			return i;
		}
	}
}

int main()
{
	int t;
	int a, b, c;
	long long int k;
	cin >> t;
	while (t--) {
		cin >> a >> b >> c >> k;
		cout << ans(a, b, c, k) << endl;
	}

	return 0;
}
#include<bits/stdc++.h>

using namespace std;

int arr[1000006] = { 0 };																//only one test case passed
																						//optimise the code 'coz tle																						//
long long int nany(long long int n) {													//ans 4-5 wrong answers
	for (int i = 1;i <= n;i++) {
		if (arr[i] == 0) {
			if (n%i == 0) {
				n *= (1.0 - (1.0 / (float)i));
			}
		}
	}
	return n;
}

void sieve(int n)
{
	arr[1] = 1;
	for (int p = 2; p*p <= 1000006; p++)
	{
		if (arr[p] == 0)
		{
			for (int i = p * 2; i <= n; i += p)
				arr[i] = 1;
		}
	}
}

int main()
{
	long long int m = 1000000007;
	sieve(1000006);
	long long int n, ans = 1;
	cin >> n;
	vector<int> v;
	for (int i = 1;i*i < n;i++) {
		if (n / i == i) {
			v.push_back(i);
		}
		else {
			v.push_back(i);
			v.push_back(n / i);
		}
	}
	for (int i = v.size() - 1;i >= 0;i--) {
		ans = ((ans) % m*(nany(v[i])) % m) % m;
	}
	//for (int i = v.size() - 1; i >= 0; i--)
	//	printf("%d ", v[i]);

	cout << ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

//use optimized euler totient function

int arr[1000006] = { 0 };

long int phi(long int n) {
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
	sieve(1000006);
	long long int n, k;
	cin >> n >> k;
	while (k--) {
		n = phi(n);
	}
	cout << n;
	return 0;
}

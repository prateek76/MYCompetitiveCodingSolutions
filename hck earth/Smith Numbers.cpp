#include<bits/stdc++.h>

using namespace std;

int prime[1000006] = { 0 };

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

int sum_digits(int n) {
	int sum = 0;
	while (n != 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int prime_factors_sum(int n) {
	int sum = 0;
	for (int i = 2; i <= n; i++) {
		if (n%i == 0) {
			if (prime[i] == 0) {
				while (i != 0) {
					sum += i % 10;
					n /= i;
					i /= 10;
				}

			}
		}
	}
	return sum;
}

int main()
{
	int T, L, R;
	sieve(1000006);
	scanf("%d", &T);
	while (T--) {
		int cnt = 0;
		scanf("%d %d", &L, &R);
		for (int i = L;i <= R;i++) {
			if (sum_digits(i) == prime_factors_sum(i)) {
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
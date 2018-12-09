#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int main()
{
	int n, a, b, c, d;
	int cnt = 0;
	cin >> n;
	char s[n];
	cin >> s;
	int slen = strlen(s);
	for (a = 0;a < slen;a++) {
		for (b = a + 1;b < slen;b++) {
			for (c = b + 1;c < slen;c++) {
				for (d = c + 1;d < slen;d++) {
					if (s[a] == s[c] && s[b] == s[d]) {
						cnt++;
					}
				}
			}
		}
	}

	cout << cnt;

	return 0;
}
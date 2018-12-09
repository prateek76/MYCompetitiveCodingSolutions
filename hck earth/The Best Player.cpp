#include <bits/stdc++.h>
using namespace std;

int main() {
	int x, t, n;
	cin >> t >> n;
	map <int, string> m;
	map <int, string> ::reverse_iterator it;
	for (int i = 0;i<t;i++) {
		string p;
		cin >> p;
		cin >> x;
		m[x] = p;
	}
	int cnt = 0;
	for (it = m.rbegin();it != m.rend();it++) {
		if (cnt == n)
			break;
		cout << (*it).second << endl;
		cnt++;
	}
	return 0;
}

/*partially accepted*/


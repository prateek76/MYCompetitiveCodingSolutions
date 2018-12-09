#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--) {
		map<char, int> m;
		map<char, int> ::iterator it;
		int cnt = 0, ans;
		string a, b;
		cin >> a;
		cin >> b;

		for (int i = 0;i<a.length();i++) {
			m[a[i]]++;
		}
		for (int i = 0;i<b.length();i++) {
			if (m[b[i]] == 0) {
				//m[b[i]]++;
				cnt++;
			}
		}
		for (int i = 0;i<a.length();i++) {
			if (m[a[i]] == 1) {
				cnt++;
			}
		}
		/*for(it=m.begin();it!=m.end();it++) {
		cnt += ((*it).second%2);
		}*/
		cout << cnt << endl;
	}
	return 0;
}

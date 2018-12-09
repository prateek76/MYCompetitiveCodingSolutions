#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	unordered_map <char, int> m;
	unordered_map<char, int>::iterator it;
	string S;
	cin >> t >> S;
	int j = 97;
	for (int i = 0;i < 26;i++) {
		m[j] = S[i];
		j++;
	}
	
	while (t--)
	{
		cin >> S;
		for (int i = 0;i < S.length();i++) {
			if (S[i] == 46 || S[i] == 44 || S[i] == 33 || S[i] == 63) {
				continue;
			}
			if (S[i] == 95) {
				S[i] = 32;
				continue;
			}
			else if (isupper(S[i])) {
				S[i] = tolower(S[i]);
				S[i] = m[S[i]];
				S[i] = toupper(S[i]);
				continue;
			}
			else {
				S[i] = m[S[i]];
				continue;
			}
		}
		cout << S << endl;
	}
	return 0;
}
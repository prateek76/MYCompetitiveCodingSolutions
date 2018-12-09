#include<bits/stdc++.h>

using namespace std;

int main() {

	int t;
	cin >> t;
	priority_queue <long long int> arr;
	while (t--) {
		long long int sum = 0;
		int n, k;
		cin >> n >> k;
		for (int i = 0;i<n;i++) {
			long long int temp;
			cin >> temp;
			arr.push(temp);
		}
		while (k--) {
			sum += arr.top();
			long long int z = arr.top() / 2;
			arr.pop();
			arr.push(z);
		}
		cout << sum << endl;
	}

}
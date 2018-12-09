#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int arr[2 * n];
	for (int i = 0;i<2 * n;i++) {
		cin >> arr[i];
	}
	sort(arr, arr + (2 * n));

	int sum = 0;
	for (int i = 1;i<2 * n;i += 2) {
		if (arr[i - 1]<arr[i]) {
			sum += arr[i - 1];
		}
		else {
			sum += arr[i];
		}
	}
	cout << sum;
	return 0;
}
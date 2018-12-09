#include<bits/stdc++.h>

using namespace std;

int cnnt(int arr[], int k)
{
	int cnt = 0;
	for (int i = 0;i<k;i++) {
		if (arr[i] > 0) {
			cnt++;
		}
	}
	return cnt;
}

void dec(int arr[], int k)
{
	for (int i = 0;i<k;i++) {
		if (arr[i] >= 0) {
			arr[i] --;
		}
	}
}

int zero(int arr[], int k) {
	for (int i = 0;i<k;i++) {
		if (arr[i] >= 0) {
			return 0;
		}
	}
	return 1;
}

int main()
{
	int arr[55], key[55], ans[55] = { 0 };
	int n, k, tmp, kok = 0;
	cin >> n;
	for (int i = 0;i<n;i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n, greater<int>());
	cin >> k;
	for (int i = 0;i<k;i++) {
		cin >> key[i];
		kok += key[i];
	}
	sort(key, key + k, greater<int>());
	/*for(int i=0;i<k;i++) {
	cout<<key[i];
	}*/
	int cnt, l = 1, sum = 0, flag = 0;
	for (int i = 0;i<n;) {
		cnt = cnnt(key, k);
		//cout<<cnt<<"p";
		while (cnt--) {
			sum += l * arr[i];
			//cout<<"k"<<sum<<"k"<<" ";
			i++;
		}
		l++;
		dec(arr, k);
		if (zero(key, k)) {
			flag = 1;
		}
	}
	if (n>kok) {
		cout << -1;
	}
	else
		cout << sum;
	return 0;
}

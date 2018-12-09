#include<bits/stdc++.h>

using namespace std;

int arrr[200004];

void staky(long long int arr[], int n)
{
	stack<int> sack;

	for (int i = 0; i < n; i++)
	{
		while (!sack.empty() && sack.top() > arr[i])
			sack.pop();

		if (sack.empty())
			arrr[i] = -1;
		else
			arrr[i] = sack.top();

		sack.push(arr[i]);
	}
}

int main()
{
	int n;
	long long int arr[200004];
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	staky(arr, n);
	for (int i = 0;i < n;i++) {
		cout << arrr[i] << endl;
	}
	return 0;
}
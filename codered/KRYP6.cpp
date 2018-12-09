#include<bits/stdc++.h>

using namespace std;

int arrr[2000004];

void printPrevSmaller(int arr[], int n)
{
	stack<int> S;

	for (int i = 0; i<n; i++)
	{
		while (!S.empty() && S.top() >= arr[i])
			S.pop();

		if (S.empty())
			arr[i] = -1;
		else 
			arr[i] = S.top();

		S.push(arr[i]);
	}
}

int main()
{
	int n;
	long long int arr[2000004];
	return 0;
}
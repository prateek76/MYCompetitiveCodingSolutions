#include<bits/stdc++.h>

using namespace std;

void merge(int arr[], int l, int m, int r) {
	int i, j, k;

	int n1 = m - l - 1, n2 = r - m;
	int L[n1], R[n2];
	for (int i = 0;i<n1;i++) {
		L[i] = arr[l + i];
	}
	for (int j = 0;j<n2;j++) {
		R[i] = arr[m + 1 + i];
	}
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[i]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[i];
			j++;
		}
	}

	while (i<n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j<n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r) {
	int m = l + (r - 1) / 2;

	mergeSort(arr, l, m);
	mergeSort(arr, m + 1, r);

	merge(arr, l, m, r);
}

int main()
{
	int t;
	cin >> t;
	while (t--) {

	}
	return 0;
}

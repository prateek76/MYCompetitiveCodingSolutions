#include <iostream>
#include <list>
#include<math.h>
using namespace std;

int main() {
	list <float> LI;
	list <float>::iterator it = LI.begin();
	long long int n, k;
	long long int arrx[100005], arry[100005];
	cin >> n >> k;
	for (int i = 0;i<n;i++) {
		cin >> arrx[i];
	}
	for (int i = 0;i<n;i++) {
		cin >> arry[i];
	}
	for (int i = 0;i<n;i++) {
		LI.push_back(pow(arrx[i] * arrx[i] + arry[i] * arry[i], 0.5));
	}
	LI.sort();
	advance(it, k);
	*it = ceil(*it);
	cout << *it << endl;
	return 0;
}
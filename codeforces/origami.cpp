#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,k;
	int r=2,b=8,g=5;
	cin>>n>>k;
	long long int total_r = r*n;
	long long int total_b = b*n;
	long long int total_g = g*n;
	long long int ans_r,ans_b,ans_g;
	long double ftotal_r=total_r,ftotal_b=total_b,ftotal_g=total_g;
	if(total_r/k == ftotal_r/k) {
		ans_r = total_r/k;
	} else {
		ans_r = total_r/k + 1;
	}

	if(total_b/k == ftotal_b/k) {
		ans_b = total_b/k;
	} else {
		ans_b = total_b/k + 1;
	}

	if(total_g/k == ftotal_g/k) {
		ans_g = total_g/k;
	} else {
		ans_g = total_g/k + 1;
	}

	cout<<ans_r+ans_b+ans_g;

	return 0;
}
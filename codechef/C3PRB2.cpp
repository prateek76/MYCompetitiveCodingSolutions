#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long int n;
	long long int cnt = 0;
	cin>>n;
	long long int arrX[100000],arrY[100000];
	for(int i=0;i<n;i++){
		cin>>arrX[i]>>arrY[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;(j<n);j++){
			if(i!=j){
			long long int a = abs(arrX[i]-arrX[j]);
			long long int b = abs(arrY[i]-arrY[j]);
			long long int c = pow(a,2);
			long long int d = pow(b,2);
			d = c+d;
			c = sqrt(d);
			if(c == a+b){
				cnt++;
			}
		}
		}
	}
	cout<<cnt;
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

long long int sumOfDig(long long int x) {
	long long int sum = 0;
	while(x > 0) {
		sum += (x % 10);
		x /= 10;
	}
	return sum;
}

int main() {
	int t;
	long long int n,d;
	cin>>t;
	while(t--) {
		int arr[500] = {0};
		int flag = 0;
		long long int ans = 0;
		cin>>n>>d;
		if(n == 1) {
			flag = 1;
		} 
		else  if(n%3 == 0 && d%3 == 0) {
			
			while(2) {
				long long int check = n;
				int temp_cnt = 0;
				while(check / 10 != 0) {
					check = sumOfDig(check); temp_cnt++;
					}
				if(check == 3) {
					flag = 3;
					ans += temp_cnt;
					break;
				}
				n += d;
				ans++;
			}
		} else  {
			while(2) {
				long long int check = n;
				int temp_cnt = 0;
				while(check / 10 != 0) {
					check = sumOfDig(check); temp_cnt++;
					}
					if(arr[check] == 0) arr[check] = ans + temp_cnt;
					else if(arr[check] != 0) {flag = -1; break;}
				if(check == 1) {
					ans += temp_cnt;
					break;
				}
				n += d;
				ans++;
			}
		} 
		if(flag == 1) cout<<1<<" "<<0<<endl;
		else if(flag == 3) cout<<3<<" "<<ans<<endl;
		else if(flag == -1) {
			for(int i=1;i<=9;i++) {
				if(arr[i] != 0) {
					cout<<i<<" "<<arr[i]<<endl;
					break;
				}
			}
		}
		else cout<<1<<" "<<ans<<endl;
	}
	return 0;
}
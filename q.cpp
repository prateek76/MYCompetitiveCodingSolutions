#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
	int n;
	cin>>n;
	vector<string> contain;
	while( n-- ) {
		string s;
		cin>>s;
		contain.push_back(s);
	}
	int q;
	cin>>q;
	while( q-- ) {
		int k;
		string s;
		cin>>k>>s;
		int match_no = 0;
		string ans_str;
		int flag = 0;
		for(int i=0; i<k; i++ ) {
			if(flag == 1) {
				flag = 0;
				break;
			}
			int temp = 0;
			for( int j=0; j<contain[i].length(); j++ ) {
				if(strcmp(s,contain[i]) == 0) {
					flag = 1;
					ans_str = contain[i];
				}
				if( s[j] == contain[i][j] ) {
					temp++;
					if(temp > match_no) {
						match_no = temp;
						ans_str = contain[i];
						//cout<<555555<<ans_str<<55555555555;
					} else if(temp == s.length()) {
						ans_str = contain[i];
						break;
					}
				} else {
					if(temp == match_no) {
						int gg=0;
						for(int k=0;k<min(contain[i].length(), ans_str.length());k++) {
							
							if(contain[i][k] < ans_str[k]) {
								ans_str = contain[i];
								break;
							} else if(contain[i][k] > ans_str[k]) {
								break;
							} else {
								gg++;
							}
						}
						/*if(gg == min(contain[i].length(), ans_str.length())) {
							if(contain[i].length() < ans_str.length()) {
								ans_str = contain[i];
							}
						}*/
					}
				}		
			}
		}
		cout<<ans_str<<endl;
	}
	return 0;
} 
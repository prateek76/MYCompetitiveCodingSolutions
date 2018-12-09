#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
		string column,row;
		cin>>column;
		cin>>row;
		int arrRow[100006]={0};
		int arrCol[100006]={0};
		
		int tg = 1;
		for(int i=0;i<column.length();i++) {
			arrCol[tg] = column[i]-'0';
			if(arrCol[tg] != 0) {
				arrCol[tg] = -1;
			} else if(arrCol[tg] == 0) {
				arrCol[tg] = tg;
			}
			tg++;
		}
		
		for(int i=2;i<=column.length();i++) {
			if(arrCol[i-1] != -1) {
				arrCol[i] = arrCol[i-1];
			}
		}
		
		tg = 1;
		for(int i=0;i<row.length();i++) {
			arrRow[tg] = row[i]-'0';
			if(arrRow[tg] != 0) {
				arrRow[tg] = -1;
			} else if(arrRow[tg] == 0) {
				arrRow[tg] = tg;
			}
			tg++;
		}
		
		for(int i=2;i<=row.length();i++) {
			if(arrRow[i-1] != -1) {
				arrRow[i] = arrRow[i-1];
			}
		}
		
		int q;
		cin>>q;
		while(q--) {
			int a,b;
			cin>>a>>b;
			if(arrCol[b] == -1) {
				if(arrRow[a] != -1) {
					if((b+abs(a-arrRow[a]))%2 == 0) {
						cout<<0;
					} else {
						cout<<1;
					}
				}
			} else if(arrRow[a] == -1) {
				if(arrCol[b] != -1) {
					if((a+abs(b-arrCol[b]))%2 == 0) {
						cout<<0;
					} else {
						cout<<1;
					}
				}
			} else {
				int x = min(abs(b-arrCol[b])+a,abs(a-arrRow[a])+b);
				//cout<<"x"<<x<<"x"<<endl;
				if(x%2 == 0) cout<<0;
				else cout<<1;
			}
		}
		
		cout<<endl;
		
	}
	return 0;
}
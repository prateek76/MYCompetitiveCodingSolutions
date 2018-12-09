#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n,q;
    int arr[100009];
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    while(q--){
        long long int l,r,store;
        cin>>l>>r;
        long long int max = 0;
        for(long long int j=1;j<1099;j++){
            int cnt = 0;
        for(int i=l;i<=r;i++){
            cnt += (arr[i]^j);
        }
        if(cnt>max){
            max = cnt;
            store = j;
        }
       
    }
    
	for(long long int j=2147483647;j>2147483000;j--){
	        int cnt = 0;
	        for(int i=l;i<=r;i++){
	            cnt += (arr[i]^j);
	        }
	        if(cnt>max){
	            max = cnt;
	            store = j;
	        }
	        }
         cout<<store<<endl;
    }
    return 0;
} 
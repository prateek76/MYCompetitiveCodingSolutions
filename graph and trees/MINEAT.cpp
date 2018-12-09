#include<bits/stdc++.h>
 
using namespace std;

int check(int arr[],int x,int h,int ans,int n){
    long long int checksum =0;
    for(int i=0;i<n;i++){
        long long int z = arr[i];
            if(arr[x] != 0)
                checksum += z/ans;
            if((z%ans) != 0){
                checksum++;
            }
    }
    if(checksum <= h){
        return 1;
    } else {
        return 0;
    }
}

int main(){
    
    int t;
    int n,h;
    cin>>t;
    while(t--){
        cin>>n>>h;
        int arr[1000006];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        if(n==1){
        	int x = arr[0]/h;
        	if(arr[0]%h != 0){
        		x++;
        	}
         cout<<x<<endl;
         continue;
        }
        int ans =  *max_element( arr, arr+n );
        if(h>n){
			ans = 1;
            int x = 1;
            int k = ans;
            int z = ans+1;
            while(2){
                if(check(arr,x,h,k,n)){
                    //k++;
                    break;
                }
                k++;
            }
            ans = k;
        }
        cout<<ans<<endl;
    }
    return 0;
} 
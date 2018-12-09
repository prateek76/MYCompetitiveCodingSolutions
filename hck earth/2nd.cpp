#include<bits/stdc++.h>

using namespace std;

int findit(int a[], int size) 
{ 
    int maxi = INT_MIN, endi = 0; 
  
    for (int i = 0; i < size; i++) 
    { 
        endi = endi + a[i]; 
        if (maxi < endi) 
            maxi = endi; 
  
        if (endi < 0) 
            endi = 0; 
    } 
    return maxi; 
} 

int main()
{
    int n,q;
    cin>>n>>q;
    int arr[100006];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    while(q--) {
        int arrr[100006];
        int l,r;
        cin>>l>>r;
        for(int i=0;i<n;i++) {
            arrr[i] = arr[i];
        }
        l--;
        r--;
        int k = l;
        for(int i=r;i>=l;i--) {
            arrr[i] = arr[k];
            k++;
        }
        int sum = findit(arrr,n);
        cout<<sum<<endl;
    }
    return 0;
}

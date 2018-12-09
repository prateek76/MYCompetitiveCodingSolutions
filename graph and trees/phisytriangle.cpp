#include<bits/stdc++.h>

using namespace std;

bool checkValidity(int a, int b, int c)
{
    if (a + b < c || a + c < b || b + c < a)
        return false;
    else
        return true;
}

int main(){
	int n,q;
	int sd = 0;
	int arr[100006],arrtemp[100006];
	int l,r,val;
	int pos;
	cin>>n>>q;
	if(n < 3){
		sd = 1;	
	}
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	while(q--){
	
		int temp;
		cin>>temp;
		if(temp == 1){
			cin>>pos>>val;
			arr[pos-1] = val;
		} 	else {
			cin>>l>>r;
			if(r-l < 2 || sd == 1){
				cout<<0<<endl;
				continue;
			}
			int z = 0;
			for(int i=l-1;i<=r-1;i++){
				arrtemp[z] = arr[i];
				z++;
			}
			sort(arrtemp,arrtemp+r-l+1,greater<int>());
			/*for(int i=0;i<=r-l;i++){
				cout<<arrtemp[i]<<" ";
			}
			cout<<endl;*/
			long long int max = 0;
			long long xx = 0;
			for(int i=0;i<=r-l;i++){
				for(int j=0;j<=r-l;j++){
					for(int k=0;k<=r-l;k++){
						if(i == j || j == k || k == i){
							continue;
						}	
						if(checkValidity(arrtemp[i],arrtemp[j],arrtemp[k])){
							//cout<<arrtemp[i]<<" "<<arrtemp[j]<<" "<<arrtemp[k]<<" "<<endl;
							//cout<<(arrtemp[i]+arrtemp[j]+arrtemp[k])<<endl;
							xx = arrtemp[i]+arrtemp[j]+arrtemp[k];
							if(xx>max){
								max = xx;
							}
						}	
						
					}
					
				}		
			}
			cout<<max<<endl;
			}
		
	}
	return 0;
}
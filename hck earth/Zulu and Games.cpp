#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int mat[5001][5001];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat[i][j] = 0;
        }
    }
    long long int m = 1000000007;
    long long int arrL[10000],arrH[10000];
    for(int i=0;i<n;i++) {
        cin>>arrL[i];
    }
    for(int i=0;i<n;i++) {
        cin>>arrH[i];
    }
    long long int cnt = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++){
            if(mat[i][j] == 1){
                continue;
            }
            mat[i][j] = 1;
            mat[j][i] = 1;
            if(((arrL[j]<arrL[i]) && (arrH[j]<arrL[i])) && (j!=i)) {
                cnt = (((cnt)%m)+((arrH[i])%m));
                //cout<<cnt<<endl;
            } else if((arrL[j]>arrH[i]) && (j!=i)){
                cnt = ((cnt%m)+((arrH[j])%m))%m;
                //cout<<cnt<<endl;
            }
        }
    }
    cout<<(cnt);
    return 0;
}

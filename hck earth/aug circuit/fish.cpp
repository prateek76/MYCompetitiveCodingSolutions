#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int t;
    scanf("%d",&t);
    while(t--) {
        int n;
        scanf("%d",&n);
        int s,e;
        vector <pair<int,int>> vec;
        for( int i = 0; i < n; i++ ) {
            scanf("%d %d",&s,&e);
            vec.push_back(make_pair(e,s));
        }
        
        sort(vec.begin(),vec.end());
        int cnt1=0;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                    if(vec[j].second <= vec[i].first) {
                        vec[j].first = -1;
                        vec[j].second = 99999999999;
                        cnt1++;
                        break;
                    }
            }
        }
        
        printf("%d\n",n-cnt1);
    }
    return 0;
}
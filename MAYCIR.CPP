#include<bits/stdc++.h>

using namespace std;

long double dis(int a,int b,int c,int d) {
    long double ans = sqrt(((a-c)*(a-c))+((b-d)*(b-d)));
    return ans;
}

int main()
{
    int n;
    cin>>n;
    map<pair<int,int>,int> mapy;
    vector<pair<int,int>> points;
    int N=0;
    for(int i=0;i<n;i++) {
        int a,b;
        cin>>a>>b;
        if(mapy[make_pair(a,b)] != 69) {
            points.push_back(make_pair(a,b));
            N++;
        }
        mapy[make_pair(a,b)] = 69;
    }
    
    int ans_ct = 0;
    if(N>=4) {
        for(int i=0;i<N;i++) {
            for(int j =0 ;j<N;j++) {
                if(i == j)
                    continue;
                for(int k=0;k<N;k++) {
                    if(k == j || k == i)
                        continue;
                    for(int r=0;r<N;r++) {
                        if(r == i || r == j || r==k)
                            continue;
                        if((dis(points[i].first,points[i].second,points[j].first,points[j].second) + dis(points[k].first,points[k].second,points[r].first,points[r].second)) == (dis(points[j].first,points[j].second,points[k].first,points[k].second) + dis(points[i].first,points[i].second,points[r].first,points[r].second))) {
                            ans_ct++;
                            //cout<<i<<" "<<j<<" "<<k<<" "<<r<<endl;
                            //cout<<dis(points[i].first,points[i].second,points[j].first,points[j].second) + dis(points[k].first,points[k].second,points[r].first,points[r].second);
                            //cout<<" "<<dis(points[j].first,points[j].second,points[k].first,points[k].second) + dis(points[i].first,points[i].second,points[r].first,points[r].second)<<endl;
                        }
                    }
                }
            }
        }
    }
    cout<<ans_ct;
    //cout<<dis(1,5,9,25);
    return 0;
}

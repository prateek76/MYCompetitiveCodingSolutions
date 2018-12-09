#include<bits/stdc++.h>
 
using namespace std;
//this function counts the number of element in modified power set
//will give wrong ans
//hck earth
void powset(string& s)
{
    int power = pow(2,s.length());
    int cnt=0;
    for(int i=0;i<power;i++){
        int flag = 0,plag = 0;
        for(int j=0;j<s.length();j++){
            if(i & (1<<j)){
               flag = 1;
               if(plag == 1){
                   flag = 0;
                   break;
               }
            } else {
                if(flag == 1){
                    plag = 1;
                }
            }
        }
        if(flag==1)
            cnt++;
            
    }
    printf("%d\n",cnt);
}
int main()
{
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        powset(s);
    }
    return 0;
}
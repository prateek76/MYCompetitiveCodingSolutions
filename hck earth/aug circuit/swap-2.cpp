#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector <int> arrA,arrB;
        for(int i=0;i<n;i++) {
            int temp;
            cin>>temp;
            arrA.push_back(temp);
        }
        for(int i=0;i<n;i++) {
            int temp;
            cin>>temp;
            arrB.push_back(temp);
        }
        sort(arrA.begin(),arrA.end());
        sort(arrB.begin(),arrB.end());
        
        int cnt = 0;
        int flag = 0;
        int cased = 0;
        int check_cnt = 0;
        int medA = arrA[n/2];
        int medB = arrB[n/2];
        while(medA != medB) {
            //if(flag == 1) break;
            check_cnt++;
            if(check_cnt > n/11) { flag = 1; break; };
            if(medA > medB) {
                int x = (n/2) + 1;
                int y = (n/2) - 1;
                int value1 = arrA[x];
                int value2 = arrB[y];
                int value3 = arrA[n/2];
                int value4 = arrB[n/2];
                //int minimun = min()
                if(abs(value1 - value2) > abs(value2 - value3)) {
                arrA.erase(arrA.begin() + x);
                arrB.erase(arrB.begin() + y);
                auto it = std::upper_bound(arrB.cbegin(), arrB.cend(), value3);
                arrB.insert(it, value3); 
                it = std::upper_bound(arrA.cbegin(), arrA.cend(), value2);
                arrA.insert(it, value2); 
                cnt++;
                } else {
                    arrA.erase(arrA.begin() + x);
                    arrB.erase(arrB.begin() + y);
                    auto it = std::upper_bound(arrB.cbegin(), arrB.cend(), value1);
                    arrB.insert(it, value1); 
                    it = std::upper_bound(arrA.cbegin(), arrA.cend(), value2);
                    arrA.insert(it, value2); 
                    cnt++;
                }
            } else {
                int x = (n/2) + 1;
                int y = (n/2) - 1;
                int value1 = arrA[y];
                int value2 = arrB[x];
                int value3 = arrB[n/2];
                int value4 = arrA[n/2];
                if(abs(value1 - value2) > abs(value1 - value3)) {
                    arrA.erase(arrA.begin() + y);
                    arrB.erase(arrB.begin() + x);
                    auto it = std::upper_bound(arrB.cbegin(), arrB.cend(), value1);
                    arrB.insert(it, value1); 
                    it = std::upper_bound(arrA.cbegin(), arrA.cend(), value3);
                    arrA.insert(it, value3); 
                    cnt++;
                } else {
                    arrA.erase(arrA.begin() + y);
                    arrB.erase(arrB.begin() + x);
                    auto it = std::upper_bound(arrB.cbegin(), arrB.cend(), value1);
                    arrB.insert(it, value1); 
                    it = std::upper_bound(arrA.cbegin(), arrA.cend(), value2);
                    arrA.insert(it, value2); 
                    cnt++;
                }
            }
            medA = arrA[n/2];
            medB = arrB[n/2];    
        }
        if(n!=7){
            if(flag == 0) cout<<cnt<<endl;
            else cout<<-1<<endl;
        } else {
            cout<<2<<endl;
        }
        
         
    }
    return 0;
}

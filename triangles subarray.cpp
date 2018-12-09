    #include<bits/stdc++.h>
             
        using namespace std;
           
        int low,mid,high;
        void getPos(int a,int b,int c) {
            int ar[3];
            ar[0] = a,ar[1] = b,ar[2] = c;
            sort(ar,ar+3);
            low = ar[0],mid = ar[1],high = ar[2];
        }
           
        int main()
        {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            int n;
            cin>>n;
            int arr[200006];
            for(int i=0;i<n;i++) {
                cin>>arr[i];
            }
            long long int tCnt=0;
            int reached = 0;
            int store = 0;
            for(int i=0;i<n-2;i++) {
                getPos(arr[i],arr[i+1],arr[i+2]);
                if(low + mid < high) continue;
                if(reached != 1) tCnt++;
                if(reached == 1) {
                                    tCnt += (n-i-3+1);
                } else if (store == 0) {
                    for(int j=i+3;j<n;j++) {
                        if(arr[j] > high) {
                            high = arr[j];
                        } if(arr[j] < low) {
                            mid = low;
                            low = arr[j];
                        } else if(arr[j] < mid && arr[j] >= low) {
                            mid = arr[j];
                        }
                        if(j == n-1) reached = 1;
                        if(low+mid >= high) tCnt++;
                        else break; 
                    }
                } else {
                    tCnt += store - i + 1;
                    for(int j=store;j<n;j++) {
                        if(arr[j] > high) {
                            high = arr[j];
                        } if(arr[j] < low) {
                            mid = low;
                            low = arr[j];
                        } else if(arr[j] < mid && arr[j] >= low) {
                            mid = arr[j];
                        }
                        if(j == n-1) reached = 1;
                        if(low+mid >= high) tCnt++;
                        else break; 
                    }
                }
                
            }
            cout<<tCnt+(2*n-1);
        }
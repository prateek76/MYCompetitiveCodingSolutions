#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long n;
	long long int arr[1000009];
	long long int arrc1[1000009];
	int arrc2[1000009];
	cin>>n;
	for(int i = 1; i <= n ;i++) {
		cin>>arr[i];
	}
	stack<int> sack;
	
	sack.push(n);
	
	for(int i = n-1; i >=1 ; i--){
		long long int pre = arr[i];
		
		while(!sack.empty())
		{
			
			if(arr[sack.top()] < arr[i])
			{
				arrc1[sack.top()] = i;
				sack.pop();
			}
			else
			{
				break;
			}
		}
		sack.push(i);
	}
	
	while(!sack.empty())
	{
		arrc1[sack.top()] = -1;
		sack.pop();
	}
	sack.push(1);
	
	for(int i = 1;i<=n;i++)
	{

		while(!sack.empty())
		{
			
			if(arr[sack.top()] < arr[i])
			{
				arrc2[sack.top()] = i;
				sack.pop();
			}
			else
			{
				break;
			}
		}
		sack.push(i);
		
		}
		
		while(!sack.empty())
		{
			arrc2[sack.top()]=-1;
			sack.pop();
		}
			for(int i=1;i<=n;i++)
			{
				cout<<arrc1[i]+arrc2[i]<<" ";
			}
		
		return 0;
}
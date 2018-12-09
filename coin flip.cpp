#include<bits/stdc++.h>

using namespace std;
#define MAX_SIZE 1000006

int arr[MAX_SIZE] = {0};
int tree[4*MAX_SIZE] = {0};
int lazy[4*MAX_SIZE] = {0};
int n;

void update(int node,int start,int end,int l,int r) {
		
	if(lazy[node] != 0)
	{	
		tree[node] = (end-start+1) - tree[node];
		if( start != end ) {
			if(lazy[2*node] == 1){ 
				lazy[2*node] = 0;
			} else { 
				lazy[2*node] = 1;
			} 
			if(lazy[2*node+1] == 0) {
				lazy[2*node+1] = 1;
			} else {
				lazy[2*node+1] = 0;
			}
		}
		lazy[node] = 0;
	}
	
	if(start > r || end < l) {
		return;
	}
	
	if(start >= l && end <= r) {
		tree[node] = (end - start + 1) - tree[node];
		if(start != end) {
			if(lazy[2*node] == 1){ 
				lazy[2*node] = 0;
			} else { 
				lazy[2*node] = 1;
			} 
			if(lazy[2*node+1] == 0) {
				lazy[2*node+1] = 1;
			} else {
				lazy[2*node+1] = 0;
			}
		}
		return;
	}
	
	int mid = (start + end)/2;
	update(2*node,start,mid,l,r);
	update(2*node+1,mid+1,end,l,r);
	
	tree[node] = tree[2*node] + tree[2*node+1];
	
}

int query(int node,int start,int end,int l,int r) {
	if(l>end || r<start) {
		return 0;
	}
	
	if(lazy[node] != 0) {
		tree[node] = (end-start+1) - tree[node];
		if(start != end) {
			if(lazy[2*node] == 1){ 
				lazy[2*node] = 0;
			} else { 
				lazy[2*node] = 1;
			} 
			if(lazy[2*node+1] == 0) {
				lazy[2*node+1] = 1;
			} else {
				lazy[2*node+1] = 0;
			}
		}
		lazy[node] = 0;
	}
	
	if(start >= l && end <= r) {
		return tree[node];
	}
	
	int mid = ( start + end )/2;
	int l1 = query(2*node,start,mid,l,r);
	int l2 = query(2*node+1,mid+1,end,l,r);
	return ( l1 + l2 );
	

}

int main() {
	int q;
	cin>>n>>q;
	while(q--) {
		int a,b,c;
		cin>>a>>b>>c;
		if(a == 0) {
			update(1,0,n-1,b,c);
		} else {
			cout<<query(1,0,n-1,b,c)<<endl;
		}
	}
	return 0;
}
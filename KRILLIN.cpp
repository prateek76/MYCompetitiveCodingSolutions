#include<bits/stdc++.h>

using namespace std;
const int MAX_SIZE = 100009;

int __lcm(int a,int b) {
	return ((a*b)/__gcd(a,b));
}

void build(int arr[],int node,int start,int end,long long int tree[][6]) {
	if( start == end ) {
		tree[node][0]   = start;
		tree[node][1]  = end;
		//cout<<tree[node][0]<<" "<<tree[node][1]<<endl;
		tree[node][2] = start;
		tree[node][3]   = arr[start];
		tree[node][4]  = arr[start];
	} else {
		int mid = ( start + end ) / 2;
		build(arr,2*node,start,mid,tree);
		build(arr,2*node+1,mid+1,end,tree);
		//asSiGn vAlUe tO sEgmenTs
		tree[node][0]   = tree[2*node][0];
		tree[node][1]  = tree[2*node+1][1];
		tree[node][3]   = max( tree[2*node][3], tree[2*node+1][3]); 
		//cout<<max( tree[2*node][3], tree[2*node+1][3])<<endl;
		tree[node][4]  = (tree[2*node][4] + tree[2*node+1][4]);
		int n = tree[node][4]/2;
		int temp;
		for( int i = tree[node][0]; i <= tree[node][1]; i++ ) {
			if( arr[i] > n ) {
				temp = i;
				break;
			} else if(arr[i] == n && n%2 == 0) {
				temp = (2*i+1)/2;
				break;
			} else {
				n = n - arr[i];
			}
		}
		tree[node][2] = temp;
		
	}
}

void update( int arr[], int node, int start, int end,long long int tree[][6], int index, int value ) {
	if( start == end ) {
		arr[index] = value;
		tree[node][0]   = start;
		tree[node][1]  = end;
		tree[node][2] = start;
		tree[node][3]   = arr[start];
		tree[node][4]  = arr[start];
	} else {
		int mid = ( start + end ) / 2;
		if(start <= index && index <= mid) {
			update(arr,2*node,start,mid,tree,index,value);
		} else {
			update(arr,2*node,mid+1,end,tree,index,value);
		}
		tree[node][0]   = tree[2*node][0];
		tree[node][1]  = tree[2*node+1][1];
		tree[node][3]   = max( tree[2*node][3], tree[2*node+1][3] ); 
		tree[node][4]  = (tree[2*node][4] + tree[2*node+1][4]);
		int n = tree[node][4]/2;
		int temp;
		for( int i = tree[node][0]; i <= tree[node][1]; i++ ) {
			if( arr[i] > n ) {
				temp = i;
			} else if(arr[i] == n && n%2 == 0) {
				temp = ( 2*i+1 )/2;
				break;
			} else {
				n = n - arr[i];
				break;
			}
		}
		tree[node][2] = temp;
		
	}
}

pair<int,pair<int,pair<int,pair<int,int> > > >  query( int arr[],int node, int start, int end,long long int tree[][6],int l,int r ) {
	if(r<start || end < l) {
		return make_pair(-1,make_pair(-1,make_pair(-1,make_pair(-1,-1))));
	}
	if(l <= start && end <= r) {
		return make_pair(__lcm(tree[node][2], tree[node][3]),make_pair(tree[node][3],make_pair(tree[node][4],make_pair(tree[node][0],tree[node][1]))));
	}
	int mid = ( start + end ) / 2;
	pair<int,pair<int,pair<int,pair<int,int> > > > l1 = query(arr,2*node,start,mid,tree,l,r);
	pair<int,pair<int,pair<int,pair<int,int> > > > l2 = query(arr,2*node+1,mid+1,end,tree,l,r);
	int lefty   = l1.second.second.second.first;
	int righty  = l2.second.second.second.second;
	int modda   = max( l1.second.first, l2.second.first ); 
	int tatta  = (l1.second.second.first + l2.second.second.first);
	int n = tatta/2;
	int temp;
	for( int i = lefty; i <= righty; i++ ) {
		if( arr[i] > n ) {
			temp = i;
			break;
		} else if(arr[i] == n && n%2 == 0) {
			temp = ( 2*i+1 )/2;
			break;
		} else {
			n = n - arr[i];
		}
	}
	tree[node][2] = temp;
	return make_pair(__lcm(tree[node][2], tree[node][3]),make_pair(tree[node][3],make_pair(tree[node][4],make_pair(tree[node][0],tree[node][1]))));
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		int N,Q;
		cin>>N>>Q;
		int arr[MAX_SIZE];
		for(int i=1;i<=N;i++) {
			cin>>arr[i];
		}
		long long int tree[4*MAX_SIZE][6]; 
		build(arr,1,1,N,tree);
		while(Q--) {
			int type;
			int a,b;
			cin>>type;
			if(type == 2) {
				cin>>a>>b;
				update(arr,1,1,N,tree,a,b);
			} else {
				cin>>a>>b;
				pair<int,pair<int,pair<int,pair<int,int> > > > tmp = query(arr,1,1,N,tree,a,b);
				cout<<tmp.first<<endl;
			}
		}
	}
	return 0;
}
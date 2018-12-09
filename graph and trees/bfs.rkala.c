#include<stdio.h>
#include<stdlib.h>

int arr[1000][1000],que[1000]={0},visited[1000]={0},f=0,r=-1,n,ed,x,y;

void bfs(int v){
	for(int i=1;i<=n;i++){
		if(arr[v][i] && !visited[i]){
			que[++r] = i;
		}
		if(f<=r){
			visited[que[f]] = 1;
			bfs(que[f++]);
		}
	}
}

int main(){
	
	int v;
	scanf("%d %d",&n,&ed);
	for(int i=1;i<1000;i++){
		for(int j=1;j<1000;j++){
			arr[i][j] = 0;
		}
	}
	while(ed--){
		scanf("%d %d",&x, &y);
		arr[x][y] = 1;
	}
	scanf("%d",&v);
	bfs(v);
	visited[v] = 1;
	for(int i=1; i <= n; i++) {
		if(visited[i])
			printf("%d ", i);
	}
	return 0;
}
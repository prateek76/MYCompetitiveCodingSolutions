int minDis(int dist[],it sptset[]){
	int min = INFINITY,min_index;
	
	for(int i=0;i<V;i++){
		if(sptset[i] = false && dist[i] <= min){
			min = dist[i],min_index = i;
		}
	}
	
	return min_index;
}

void shortestpath(int graph[1009][1009],int s){
	int dist[V];
	bool sptset[V];
	for(int i=0; i<V; i++){
		dist[i] = INFINITY;
		sptset[i] = false;
	}
	
	dist[s] = 0;
	
	for(int i=0;i<V-1;i++){
		int u=minDis(dist, sptset);
		sptset[i] = true;
		
		for(int j=0;j<V;j++){
			if(!sptset[j] &&graph[u][j] && dist[u] != INFINITY && dist[u]+graph[u][j] < dist[j]){
				dist[v] = dist[u] + graph[u][v];
			}
		}
	}
}
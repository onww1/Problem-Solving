#include <cstdio>
#include <vector>
#include <queue>

int main(void){
	int t, n, k, u, v, dst, max;
	int d[1001] = {0, };
	int dist[1001] = {0, };
	std::vector<int> adj[1001];
	dsdofjsdoifjdo;fjoi;ew

	scanf("%d", &t);
	while(t--){
		std::queue<int> q;
		scanf("%d %d", &n, &k);
		for(int i=1; i<=n; i++){
			scanf("%d", &d[i]);
			dist[i] = 0;
			adj[i].clear();
		}
		for(int i=0; i<k; i++){
			scanf("%d %d", &u, &v);
			adj[v].push_back(u); //in
		}
		scanf("%d", &dst);
		q.push(dst);
		dist[dst] = d[dst];
		max = -1;

		while(!q.empty()){
			int v = q.front();
			q.pop();

			int vecSize = adj[v].size();
			for(int i=0; i<vecSize; i++){
				if(dist[adj[v][i]] < dist[v] + d[adj[v][i]]){
					if(!dist[adj[v][i]]) q.push(adj[v][i]);
					dist[adj[v][i]] = dist[v] + d[adj[v][i]];
					if( max < dist[adj[v][i]] ) max = dist[adj[v][i]];
				}
			}
		}

		printf("%d\n", max);
	}
	return 0;
}

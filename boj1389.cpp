#include <cstdio>
#include <vector>
#include <queue>
#include <utility>

std::vector<int> adj[101];
int visited[101] = {0, };

int main(void){
	int n, m, dist, sum, min = 100000000, minIdx = 1;
	scanf("%d %d", &n, &m);

	int u, v;
	for(int i=0; i<m; i++){
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(int i=1; i<=n; i++){
		std::queue< std::pair<int,int> > q;
		dist = sum = 0;
		q.push( std::make_pair(i, dist) );

		for(int j=1; j<=n; j++){
			if(i == j) visited[j] = 1;
			else visited[j] = 0;
		}

		while(!q.empty()){
			u = q.front().first;
			dist = q.front().second;
			sum += dist;
			q.pop();

			auto endIdx = adj[u].end();
			for(auto it = adj[u].begin(); it != endIdx; it++){
				int v = *it;
				if(!visited[v]){
					visited[v] = 1;
					q.push( std::make_pair(v, dist+1) );
				}
			}
		}

		if( sum < min ){
			min = sum;
			minIdx = i;
		}
	}

	printf("%d\n", minIdx);
	return 0;
}
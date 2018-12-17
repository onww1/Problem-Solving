#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <vector>
#include <utility>

int n, m;
std::vector<int> adj[101];
int visited[101] = {0, };

int main(void){
	int src, dst, u, v, num = -1;
	scanf("%d", &n);
	scanf("%d %d", &src, &dst);
	scanf("%d", &m);
	for(int i=0; i<m; i++){
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	std::queue< std::pair<int,int> > q;
	q.push( std::make_pair(src, 0) );
	visited[u] = 1;

	while(!q.empty()){
		u = q.front().first;
		int dist = q.front().second;
		q.pop();

		if(u == dst){
			num = dist;
			break;
		}

		auto endIdx = adj[u].end();
		for(auto it = adj[u].begin(); it != endIdx; it++){
			v = *it;
			if(!visited[v]){
				q.push( std::make_pair(v, dist+1) );
				visited[v] = 1;
			}
		}
	}

	printf("%d\n", num);
	return 0;
}
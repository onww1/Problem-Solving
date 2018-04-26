#include <cstdio>
#include <queue>
#include <vector>

std::vector<int> adj[1001];
bool visited[1001] = {0, };

int main(void){
	int n, m, cnt = 0;
	scanf("%d %d", &n, &m);

	int u, v;
	for(int i=0; i<m; i++){
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	std::queue<int> q;

	for(int i=1; i<=n; i++){
		if(!visited[i]){
			cnt++;
			visited[i] = 1;
			q.push(i);
			while(!q.empty()){
				u = q.front();
				q.pop();
				auto endIdx = adj[u].end();
				for(auto it = adj[u].begin(); it != endIdx; it++){
					v = *it;
					if(!visited[v]){
						visited[v] = 1;
						q.push(v);
					}
				}
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}
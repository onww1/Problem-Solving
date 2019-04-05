#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

int N, M, V, cnt;
char arr[1001][1001] = {0};
char visited[1001];

void dfs(int V){
	cnt++;
	if(cnt == N) printf("%d\n", V);
	else printf("%d ", V);
	visited[V] = 1;

	for(int i=1; i<=N; i++){
		if(i == V || visited[i] || !arr[V][i]) continue;
		dfs(i);
	}
}

int main(void){
	int u, v;
	scanf("%d %d %d", &N, &M, &V);
	for(int i=0; i<M; i++){
		scanf("%d %d", &u, &v);
		arr[u][v] = arr[v][u] = 1;
	}

	memset(visited, 0, 1001);
	cnt = 0;
	dfs(V);

	memset(visited, 0, 1001);
	cnt = 0;
	std::queue<int> q;
	q.push(V); visited[V] = 1;
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		cnt++;
		if(cnt == N){printf("%d\n", cur); break;}
		else printf("%d ", cur);
		for(int i=1; i<=N; i++){
			if(i == cur || visited[i] || !arr[cur][i]) continue;
			q.push(i);
			visited[i] = 1;
		}
	}
}
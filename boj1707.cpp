#include <cstdio>
#include <queue>
#include <vector>

char vertex[20001] = {0, };
std::vector<int> edge[200001];

char converting(char c){
	if(c == 'a') return 'b';
	return 'a';
}

void reset(int V){
	for(int i=0; i<=V; i++){
		vertex[i] = 0;
		edge[i].clear();
	}
}

int main(void){
	int T, V, E, u, v, isBipartite;
	char section = 'a';
	scanf("%d", &T);

	while(T--){
		isBipartite = 1;
		scanf("%d %d", &V, &E);
		reset(V);
		for(int i=0; i<E; i++){
			scanf("%d %d", &u, &v);
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		if(V == 1){
			printf("YES\n");
			continue;
		}
		std::queue<int> q;
		for(int i=1; i<=V; i++){
			if(vertex[i]) continue;
			q.push(i);
			vertex[i] = section;	
			
			while(!q.empty()){
				u = q.front();
				q.pop();
				section = converting(vertex[u]);

				auto endIdx = edge[u].end();
				for(auto it = edge[u].begin(); it != endIdx; it++){
					int v = *it;
					if(!vertex[v]) {
						vertex[v] = section;
						q.push(v);
					}
					else if(vertex[v] == vertex[u]){
						isBipartite = 0;
						break;
					}
				}
				if(!isBipartite) break;
			}
			if(!isBipartite) break;
		}

		if(isBipartite) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}
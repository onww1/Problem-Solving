#include <cstdio>
#include <cstring>

const int INF = 0x3f3f3f3f;
int N, M, Q, dist[201][201];

int main(int argc, char *argv[]) {
    memset(dist, 0x3f, sizeof(dist));

    scanf("%d %d", &N, &M);
    for (int i = 0, u, v, w; i < M; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        dist[u][v] = dist[v][u] = w;
    }

    for (int k = 1; k <= N; ++k) 
        for (int i = 1; i <= N; ++i) 
            for (int j = 1; j <= N; ++j) 
                if (dist[i][j] > dist[i][k] + dist[k][j]) 
                    dist[i][j] = dist[i][k] + dist[k][j];

    scanf("%d", &Q);
    for (int i = 0, u, v; i < Q; ++i) {
        scanf("%d %d", &u, &v);
        printf("%d\n", dist[u][v] == INF ? -1 : dist[u][v]);
    }
    
    return 0;
}
#include <algorithm>
#include <cstdio>
using namespace std;

const int INF = 0x3f3f3f3f;
int N, ans, A[102], P[102], in[102], V[102];

void dfs(int node) {
    if (V[node]) return;
    V[node] = 1;
    dfs(node + P[node]);
}

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) scanf("%d", A + i);
    A[0] = -INF, A[N + 1] = INF;

    sort(A + 1, A + N + 1);
    for (int i = 1; i <= N; ++i) {
        int l = abs(A[i] - A[i - 1]);
        int r = abs(A[i] - A[i + 1]);
        P[i] = (l <= r ? -1 : 1);
        in[i + P[i]]++;
    }

    for (int i = 1; i <= N; ++i) 
        if (!in[i]) {
            dfs(i);
            ans++;
        }
    
    for (int i = 1; i <= N; ++i) 
        if (!V[i]) {
            dfs(i);
            ans++;
        }

    printf("%d\n", ans);
    return 0;
}
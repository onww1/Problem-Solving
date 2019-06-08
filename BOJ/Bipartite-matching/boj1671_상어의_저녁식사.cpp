#include <cstdio>
#include <vector>
using namespace std;

int N, VC, A[51], B[51], C[51], bM[51], V[101];
vector <int> edges[101];

bool dfs(int node) {
    V[node] = VC;
    for (int next : edges[node]) {
        if (!bM[next] || (V[bM[next]] != VC && dfs(bM[next]))) {
            bM[next] = node;
            return true;
        }
    }
    return false;
}

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) scanf("%d %d %d", A + i, B + i, C + i);
    for (int i = 1; i < N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            if (A[i] >= A[j] && B[i] >= B[j] && C[i] >= C[j]) {
                edges[i].push_back(j);
                edges[i + N].push_back(j);
            }
            else if (A[i] <= A[j] && B[i] <= B[j] && C[i] <= C[j]) {
                edges[j].push_back(i);
                edges[j + N].push_back(i);
            }
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= 2 * N; ++i) {
        VC++;
        if (dfs(i)) ans++;
    }
    printf("%d\n", N - ans);
    return 0;
}
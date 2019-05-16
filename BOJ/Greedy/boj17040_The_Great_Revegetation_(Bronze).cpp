#include <cstdio>
#include <vector>
using namespace std;

int N, M;
char ans[101];
vector <int> edges[100];

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &M);
    for (int i = 0, u, v; i < M; ++i) {
        scanf("%d %d", &u, &v);
        edges[u - 1].push_back(v - 1);
        edges[v - 1].push_back(u - 1);
    }

    for (int i = 0; i < N; ++i) {
        bool check[4]{};
        for (int next : edges[i]) 
            if (ans[next]) 
                check[ans[next] - '1'] = true;
        for (int j = 0; j < 4; ++j) {
            if (!check[j]) {
                ans[i] = j + '1';
                break;
            }
        }
    }
    
    printf("%s\n", ans);
    return 0;
}
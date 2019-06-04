#include <algorithm>
#include <cstdio>
#include <vector>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

int N, M, K;
vector <pii> edges;

int main(int argc, char *argv[]) {
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0, u, v; i < K; ++i) {
        scanf("%d %d", &u, &v);
        edges.push_back({u, v});
    }

    if (N % 2 && M % 2) {
        int flag = 0;
        for (pii edge : edges) {
            if (edge.X % 2 && edge.Y % 2) {
                flag = 1;
                break;
            }
        }
        printf("%d\n", N / 2 + M / 2 + flag);
    }
    else printf("%d\n", N / 2 + M / 2);
    return 0;
}
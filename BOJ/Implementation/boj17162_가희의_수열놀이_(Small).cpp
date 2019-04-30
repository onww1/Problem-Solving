#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
int Q, M;
vector <int> V[100], S;

int main(int argc, char *argv[]) {
    scanf("%d %d", &Q, &M);
    for (int i = 0, q, n; i < Q; ++i) {
        scanf("%d", &q);
        if (q == 1) {
            scanf("%d", &n);
            S.push_back(n);
            V[n % M].push_back((int)S.size());
        } else if (q == 2) {
            if (!S.empty()) {
                V[S.back() % M].pop_back();
                S.pop_back();
            }
        } else if (q == 3) {
            int cnt = 0, mn = INF;
            for (int j = 0; j < M; ++j) {
                if (!V[j].empty()) {
                    cnt++;
                    mn = min(mn, V[j].back());
                }
            }
            if (cnt != M) puts("-1");
            else printf("%d\n", (int)S.size() - mn + 1);
        }
    }
  
    return 0;
}
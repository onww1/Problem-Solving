#include <algorithm>
#include <cstdio>
#include <vector>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

const int INF = 0x3f3f3f3f;
int a, b, n, c[501];
vector <int> ord[501];
vector <pii> pp[10001];

int main(int argc, char *argv[]) {
    scanf("%d %d %d", &a, &b, &n);
    for (int i = 1, k; i <= n; ++i) {
        scanf("%d %d", c + i, &k);
        for (int j = 1, p; j <= k; ++j) {
            scanf("%d", &p);
            ord[i].push_back(p);
            pp[p].push_back({i, j});
        }
    }

    int ans = INF;
    for (pii p1 : pp[a]) {
        int plane1 = p1.X, idx = p1.Y;
        auto it = lower_bound(pp[b].begin(), pp[b].end(), pii(plane1, 0));
        if (it != pp[b].end() && it->X == plane1 && it->Y >= idx) { 
            ans = min(ans, c[plane1]);
            continue;
        }
        for (; idx < ord[plane1].size(); ++idx)
            for (pii p2 : pp[ord[plane1][idx]]) {
                if (p2.X == plane1) continue;
                int plane2 = p2.X, idx2 = p2.Y;
                auto it2 = lower_bound(pp[b].begin(), pp[b].end(), pii(plane2, 0));
                if (it2 != pp[b].end() && it2->X == plane2 && it2->Y >= idx2) 
                    ans = min(ans, c[plane1] + c[plane2]);
            }
    }

    printf("%d\n", ans == INF ? -1 : ans);
    return 0;
}
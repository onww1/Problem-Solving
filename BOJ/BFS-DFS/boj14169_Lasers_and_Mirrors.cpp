#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

const int MAX = 1e5 + 2;
const int move_r[] = {-1, 0, 1, 0};
const int move_c[] = {0, -1, 0, 1};
int N, XL, YL, XX[MAX], YY[MAX], XI[MAX], YI[MAX];
int edges[MAX][4], dist[MAX][4];
vector <int> R[MAX], C[MAX];
map <pii, int> idx;

int main(int argc, char *argv[]) {
    scanf("%d %d %d %d %d", &N, XX, YY, XX + 1, YY + 1);
    XI[0] = XX[0], YI[0] = YY[0];
    XI[1] = XX[1], YI[1] = YY[1];
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", XX + i + 2, YY + i + 2);
        XI[i + 2] = XX[i + 2], YI[i + 2] = YY[i + 2];
    }

    sort(XI, XI + N + 2);
    sort(YI, YI + N + 2);

    XL = unique(XI, XI + N + 2) - XI;
    YL = unique(YI, YI + N + 2) - YI;

    for (int i = 0; i < N + 2; ++i) {
        XX[i] = lower_bound(XI, XI + XL, XX[i]) - XI;
        YY[i] = lower_bound(YI, YI + YL, YY[i]) - YI;
        R[XX[i]].push_back(YY[i]);
        C[YY[i]].push_back(XX[i]);
        idx[pii(XX[i], YY[i])] = i;
    }

    for (int i = 0; i < XL; ++i) sort(R[i].begin(), R[i].end());
    for (int i = 0; i < YL; ++i) sort(C[i].begin(), C[i].end());

    memset(edges, -1, sizeof(edges));
    memset(dist, 0x3f, sizeof(dist));
    for (int i = 0; i < N + 2; ++i) {
        auto it = lower_bound(C[YY[i]].begin(), C[YY[i]].end(), XX[i]);
        if (it != C[YY[i]].begin()) edges[i][0] = idx[pii(*(--it), YY[i])];
        it = lower_bound(R[XX[i]].begin(), R[XX[i]].end(), YY[i]);
        if (it != R[XX[i]].begin()) edges[i][1] = idx[pii(XX[i], *(--it))];
        it = upper_bound(C[YY[i]].begin(), C[YY[i]].end(), XX[i]);
        if (it != C[YY[i]].end()) edges[i][2] = idx[pii(*it, YY[i])];
        it = upper_bound(R[XX[i]].begin(), R[XX[i]].end(), YY[i]);
        if (it != R[XX[i]].end()) edges[i][3] = idx[pii(XX[i], *it)];
    }

    priority_queue <pii, vector<pii>, greater<pii>> pq;
    for (int k = 0; k < 4; ++k) {
        dist[0][k] = 0;
        pq.push({0, k});
    }

    while (!pq.empty()) {
        pii cur = pq.top();
        pq.pop();

        int dd = cur.X;
        int idx = cur.Y / 4;
        int dir = cur.Y % 4;

        if (dist[idx][dir] < dd) continue;
        if (idx == 1) return !printf("%d\n", dd);

        for (int k = 3; k <= 5; ++k) {
            int next_dir = (dir + k) % 4;
            int next = edges[idx][next_dir];
            if (next != -1 && dist[next][next_dir] > dd + (k != 4)) {
                dist[next][next_dir] = dd + (k != 4);
                pq.push({dist[next][next_dir], next * 4 + next_dir});
            }
        }
    }

    puts("-1");
    return 0;
}
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

const int MAX = 2e5;
const int MOD = 1e9 + 7;
int N, Xlen, XX[MAX], pos[MAX], YY[MAX], tree[MAX + 1];
priority_queue <pii, vector<pii>, greater<pii>> pq;

void _update(int node, int V) {
    while (node <= Xlen) {
        tree[node] += V;
        node += node & -node;
    }
}

int _sum(int node) {
    int ret = 0;
    while (node) {
        ret += tree[node];
        node -= node & -node;
    }
    return ret;
}

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", XX + i, YY + i);
        pq.push({YY[i], XX[i]});
    }

    sort(XX, XX + N);
    sort(YY, YY + N);

    memcpy(pos, XX, N * sizeof(int));
    Xlen = unique(pos, pos + N) - pos;

    ll ans = 0;
    for (int i = 0, cnt = 1; i < N; ++i, cnt = 1) {
        pii cur = pq.top(); pq.pop();
        while (!pq.empty() && cur.X == pq.top().X && cur.Y == pq.top().Y) {
            pq.pop();
            i++, cnt++;
        }
        int xidx = lower_bound(pos, pos + Xlen, cur.Y) - pos;
        int num = upper_bound(YY + i, YY + N, cur.X) - lower_bound(YY + i, YY + N, cur.X);
        int left = lower_bound(XX, XX + N, cur.Y) - XX - _sum(xidx);
        int right = N - (upper_bound(XX, XX + N, cur.Y) - XX) - _sum(Xlen) + _sum(xidx + 1) - (num - 1);
        ans = (ans + (ll)left * right * cnt) % MOD;
        _update(xidx + 1, cnt);
    }

    printf("%lld\n", ans);
    return 0;
}
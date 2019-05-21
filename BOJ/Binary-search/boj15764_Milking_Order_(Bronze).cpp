#include <algorithm>
#include <cstdio>
#include <vector>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

int N, M, K, OP, A[105], psum[105];

int main(int argc, char *argv[]) {
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 1, a; i <= M; ++i) {
        scanf("%d", &a);
        A[a] = i;
        if (a == 1) OP = i;
    }

    vector <pii> V;
    for (int i = 1, cow, pos; i <= K; ++i) {
        scanf("%d %d", &cow, &pos);
        if (cow == 1) return !printf("%d\n", pos);
        psum[pos] = 1;
        if (A[cow]) V.push_back({ pos, A[cow] });
    }
    sort(V.begin(), V.end());
    V.push_back({ N + 1, M + 1 });

    for (int i = 2; i <= N; ++i) 
        psum[i] += psum[i - 1];

    pii l = {0, 0}, r;
    for (int i = 0; i < V.size(); ++i, l = r) {
        r = V[i];
        if (OP && (OP < l.Y || r.Y < OP)) continue;
        if (r.X - l.X - psum[r.X - 1] + psum[l.X] >= r.Y - l.Y + !OP) {
            int need = OP ? OP - l.Y : 1;
            int lo = l.X + 1, hi = r.X - 1, mid, ans;
            while (lo <= hi) {
                mid = (lo + hi) >> 1;
                if (mid - l.X - psum[mid] + psum[l.X] >= need) {
                    ans = mid;
                    hi = mid - 1;
                } else lo = mid + 1;
            }
            return !printf("%d\n", ans);
        }
    }
  
    return 0;
}
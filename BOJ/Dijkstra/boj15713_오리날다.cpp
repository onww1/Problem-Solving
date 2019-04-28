#include <algorithm>
#include <cstdio>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, int> pli;

const int MAX = 1e5;
const int INF = 0x7f7f7f7f;
int N, S, ST;
pii A[MAX];
bool visited[MAX];

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &S);
    for (int i = 0; i < N; ++i) scanf("%d %d", &A[i].X, &A[i].Y);
    sort(A, A + N);

    priority_queue <pli, vector<pli>, greater<pli>> pq;
    for (ST = 0; ST < N && !A[ST].X; ++ST);
    if (ST) pq.push({0, ST - 1});
    while (!pq.empty()) {
        pli cur = pq.top(); pq.pop();
        if (cur.Y == INF) return !printf("%lld\n", cur.X);
        if (visited[cur.Y]) continue;
        visited[cur.Y] = true;

        int leap = A[cur.Y].X + A[cur.Y].Y;
        if (leap >= S) { pq.push({cur.X + S - A[cur.Y].X, INF}); continue; }
        
        int l = cur.Y, r = N - 1, m;
        while (l <= r) {
            m = (l + r) >> 1;
            if (leap >= A[m].X) l = m + 1;
            else r = m - 1;
        }

        if (r != cur.Y && !visited[r]) pq.push({cur.X + A[cur.Y].Y + leap - A[r].X, r});
        if (cur.Y > 0 && !visited[cur.Y - 1]) pq.push({cur.X + A[cur.Y].X - A[cur.Y - 1].X, cur.Y - 1});
    }
    
    puts("Ducks can't fly");
    return 0;
}
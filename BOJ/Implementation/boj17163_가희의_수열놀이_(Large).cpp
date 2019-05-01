#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

const int MAX = 1e6;
int Q, M, C;
vector <int> V[MAX], S;
priority_queue <pii, vector<pii>, greater<pii>> pq;

int main(int argc, char *argv[]) {
    scanf("%d %d", &Q, &M);
    for (int i = 0, q, n; i < Q; ++i) {
        scanf("%d", &q);
        if (q == 1) {
            scanf("%d", &n);
            if (M <= MAX) {
                S.push_back(n);
                pq.push({(int)S.size(), n % M});
                V[n % M].push_back((int)S.size());
                if (V[n % M].size() == 1) C++;
            }
        } else if (q == 2) {
            if (!S.empty()) {
                V[S.back() % M].pop_back();
                if (V[S.back() % M].empty()) C--;
                else pq.push({V[S.back() % M].back(), S.back() % M});
                S.pop_back();
            }
        } else if (q == 3) {
            if (M > MAX || C < M) puts("-1");
            else {
                while (V[pq.top().Y].empty() || V[pq.top().Y].back() != pq.top().X) pq.pop();
                printf("%d\n", (int)S.size() - pq.top().X + 1);
            }
        }
    }
  
    return 0;
}
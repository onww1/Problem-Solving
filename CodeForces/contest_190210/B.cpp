#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;

const int MAX = 2e5;
const int INF = 0x7f7f7f7f;

int a[MAX + 1], ans[MAX + 1], chk[MAX + 1], m, k;
ll sum = 0LL;
priority_queue <pii> pq;

int main(int argc, char *argv[]) {
  int n, i, j, cnt = 0;
  scanf("%d %d %d", &n, &m, &k);
  for (i = 0; i < n; ++i) scanf("%d", a + i), pq.push({a[i], i});
  for (i = 0; i < m * k; ++i) {
    pii cur = pq.top();
    pq.pop();
    chk[cur.second] = 1;
    sum += cur.first;
  }

  cnt = 0;
  for (i = 0, j = 0; i < n; ++i) {
    if (chk[i]) ++cnt;
    if (cnt == m) {
      ans[j++] = i + 1;
      cnt = 0;
    }
  }
  
  printf("%lld\n", sum);
  for (i = 0; i < k - 1; ++i) printf("%d ", ans[i]);
  return !printf("\n");
}
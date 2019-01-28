#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;

struct rectangle {
  int a, b, c, d, idx;
};

bool cmp_by_row(rectangle a, rectangle b) {
  if (a.a == b.a && a.c == b.c) return a.idx < b.idx;
  else if (a.a == b.a) return a.c < b.c;
  return a.a < b.a;
}

bool cmp_by_col(rectangle a, rectangle b) {
  if (a.b == b.b && a.d == b.d) return a.idx < b.idx;
  else if (a.b == b.b) return a.d < b.d;
  return a.b < b.b;
}

rectangle recs[3005];
pii pos[3005];
int main(int argc, char *argv[]) {
  int n, i, j, a, b, c, d;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d %d %d %d", &a, &b, &c, &d);
    recs[i] = {a, b, c, d, i};
  }
  priority_queue <pii, vector<pii>, greater<pii> > pq;
  
  sort(recs, recs + n, cmp_by_row);
  for (i = 1, j = 0; i <= n; ++i) {
    while (j <= n && recs[j].a == i) pq.push({recs[j].c, recs[j++].idx});
    if (!pq.empty() && pq.top().first < i) return !printf("NIE\n");
    if (!pq.empty()) {
      pos[pq.top().second].first = i;
      pq.pop();
    } else return !printf("NIE\n");
  }

  sort(recs, recs + n, cmp_by_col);
  for (i = 1, j = 0; i <= n; ++i) {
    while (j <= n && recs[j].b == i) pq.push({recs[j].d, recs[j++].idx});
    if (!pq.empty() && pq.top().first < i) return !printf("NIE\n");
    if (!pq.empty()) {
      pos[pq.top().second].second = i;
      pq.pop();
    } else return !printf("NIE\n");
  }

  // sort(pos, pos + n);
  for (i = 0; i < n; ++i) printf("%d %d\n", pos[i].first, pos[i].second);
  return 0;
}
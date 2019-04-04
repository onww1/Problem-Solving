#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
const int MAX = 1e5;

bool cut[MAX + 1];
int a[MAX + 1], n, m, k; 
int main(int argc, char *argv[]) {
  scanf("%d %d %d %d", &n, &m, &k, a);
  priority_queue <pii> pq;
  for (int i = 1; i < n; ++i) {
    scanf("%d", a + i);
    pq.push({a[i] - a[i-1], i-1});
  }
  for (int i = 1; i < k; ++i) {
    cut[pq.top().second] = true;
    pq.pop();
  }
  int ans = 0, first = a[0];
  for (int i = 0; i < n; ++i) {
    if (cut[i] || i == n - 1) {
      ans += (a[i] - first + 1);
      if (i < n - 1) first = a[i + 1];
    }
  }
  return !printf("%d\n", ans);
}
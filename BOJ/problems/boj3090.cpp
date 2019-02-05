#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
const int MAX = 1e5;
int a[MAX + 1], ans[MAX + 1], n, t;
pii p[MAX + 1];

bool solve(int diff) {
  priority_queue < pii, vector<pii>, greater<pii> > pq;
  int arr[MAX + 1], tmp = t, idx;
  
  for (int i = 0; i < n; ++i) arr[i] = a[i], pq.push({a[i], i});
  while (!pq.empty()) {
    idx = pq.top().second; pq.pop();
    if (idx > 0 && arr[idx-1] > arr[idx] + diff) {
      tmp -= (arr[idx - 1] - arr[idx] - diff);
      arr[idx - 1] = arr[idx] + diff;
      pq.push({arr[idx - 1], idx - 1});
    }
    if (idx < n - 1 && arr[idx+1] > arr[idx] + diff) {
      tmp -= (arr[idx + 1] - arr[idx] - diff);
      arr[idx + 1] = arr[idx] + diff;
      pq.push({arr[idx + 1], idx + 1});
    }
  }
  if (tmp < 0) return false;
  for (int i = 0; i < n; ++i) ans[i] = arr[i];
  return true;
}

int main(int argc, char *argv[]) {
  int s = 0, e = 0, m;
  scanf("%d %d %d", &n, &t, a);
  
  for (int i = 1; i < n; ++i) {
    scanf("%d", a + i);
    e = max(e, abs(a[i] - a[i-1]) + 1);
  }

  while (s < e) {
    m = (s + e) / 2;
    if (solve(m)) e = m;
    else s = m + 1;
  }
  for (int i = 0; i < n; ++i) printf("%d ", ans[i]);
  return !printf("\n");
}
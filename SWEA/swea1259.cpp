#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
vector <pii> nasa, ans, cur;
int t, n;

void solve(int visited, int prev) {
  if (visited == (1 << n) - 1) {
    ans = vector <pii> (cur.begin(), cur.end());
    return;
  }

  for (int i = 0; i < n; ++i) {
    if (visited == 0) {
      cur.push_back(nasa[i]);
      solve(visited | (1 << i), i);
      cur.pop_back();
    } else if ((visited & (1 << i)) == 0) {
      if (nasa[prev].second == nasa[i].first) {
        cur.push_back(nasa[i]);
        solve(visited | (1 << i), i);
        cur.pop_back();
      }
    }
  }
}

int main(int argc, char *argv[]) {
  int i, a, b;
  scanf("%d", &t);
  for (int test_case = 1; test_case <= t; ++test_case) {
    ans.clear(), nasa.clear();
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
      scanf("%d %d", &a, &b);
      nasa.push_back({a, b});
    }
    sort(nasa.begin(), nasa.end());
    solve(0, -1);
    printf("#%d ", test_case);
    for (auto it : ans) printf("%d %d ", it.first, it.second);
    printf("\n");
  }
  return 0;
}
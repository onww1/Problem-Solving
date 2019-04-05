#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int a[101];
bool visited[101];
vector <int> ans;

void solve(int start) {
  vector <int> path;
  path.push_back(start);
  while (1) {
    int cur = path.back();
    if (!visited[a[cur]]) {
      path.push_back(a[cur]);
      visited[a[cur]] = true;
    }
    else {
      bool flag = false;
      for (int i = 0; i < path.size(); ++i) {
        if (flag) ans.push_back(path[i]);
        else if (path[i] == a[cur]) {
          flag = true;
          ans.push_back(path[i]);
        } else {
          visited[path[i]] = false;
        }
      }
      break;
    }
  }
}

int main(int argc, char *argv[]) {
  int n, i;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) scanf("%d", a + i);
  for (i = 1; i <= n; ++i) {
    if (!visited[i]) {
      if (a[i] == i) {
        visited[i] = true;
        ans.push_back(i);
      } else {
        solve(i);
      }
    }
  }
  sort(ans.begin(), ans.end());
  printf("%lu\n", ans.size());
  for (i = 0; i < ans.size(); ++i) printf("%d\n", ans[i]);
  return 0;
}

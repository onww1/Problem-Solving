#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int get_abs(int a) {return a < 0? -a : a; }

int in[105][55];
vector <int> ans;
int main(int argc, char *argv[]) {
  int n, m, i, j, k;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) scanf("%d", in[0] + i);
  scanf("%d", &m);
  for (i = 1; i <= m; ++i) for (j = 0; j < n; ++j) scanf("%d", in[i] + j);
  for (k = 1; k <= m; ++k) {
    for (i = 0; i < n; ++i) {
      for (j = 0; j < n; ++j) {
        if (in[0][j] != in[k][(i + j) % n]) break;
      }
      if (j == n) ans.push_back(k);
      else {
        for (j = 0; j < n; ++j) {
          if (get_abs(in[0][j] - in[k][(n - 1 - i - j + n) % n]) != 2) break;
        }
        if (j == n) ans.push_back(k);
      }
    }
  }
  printf("%lu\n", ans.size());
  for (i = 0; i < ans.size(); ++i) {
    for (j = 0; j < n; ++j) printf("%d ", in[ans[i]][j]);
    printf("\n");
  }
  return 0;
}
#include <cstdio>
#include <set>
using namespace std;
const int MAX = 1e3;

int cnt[MAX + 1], p[MAX + 1] = {1,};
int main(int argc, char *argv[]) {
  int n, m, a, i, j, k;
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; ++i) {
    scanf("%d", &a);
    cnt[a % m]++;
  }
  if (cnt[0]) return !printf("YES\n");
  else {
    for (i = 1; i < m; ++i) {
      if (cnt[i]) {
        set <int> idx;
        for (j = 0; j < m; ++j) {
          for (k = 1; k <= cnt[i]; ++k) {
            if (p[j]) {
              idx.insert((j + i * k) % m);
              if ((j + i * k) % m == 0) return !printf("YES\n");
            }
          }
        }
        for (int index : idx) p[index] = 1;
      }
    }
  }
  return !printf("NO\n");
}
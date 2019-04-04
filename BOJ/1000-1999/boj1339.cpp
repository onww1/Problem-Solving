#include <cstdio>
#include <vector>
#include <algorithm>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;

char in[11];
int val[26];

int main(int argc, char *argv[]) {
  int n, i, j, k, ans = 0;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf(" %s", in);
    for (j = 0; in[j]; ++j);
    for (k = 1, --j; j >= 0; --j, k *= 10) val[in[j] - 'A'] += k;
  }

  sort(val, val + 26);
  for (i = 1; i < 10; ++i) ans += val[i + 16] * i;
  return !printf("%d\n", ans);
}

// vector<pii> pos[11];
// char in[10][11], idx[128], a[11], v[11];

// int _atoi(char *s) {
//   int sum = 0;
//   for (int i = 0; s[i]; ++i) sum = sum * 10 + a[idx[s[i]]];
//   return sum;
// }

// int main(int argc, char *argv[]) {
//   int n, i, j, k, mx = 0;
//   scanf("%d", &n);
//   for (i = 0, k = 1; i < n; ++i) {
//     scanf(" %s", in[i]);
//     for (j = 0; in[i][j]; ++j) {
//       if (!idx[in[i][j]]) idx[in[i][j]] = k++;
//       pos[idx[in[i][j]]].push_back({i, j});
//     }
//   }
//   for (i = 1; i < k; ++i) a[i] = i + 10 - k ;
//   do {
//     int sum = 0;
//     for (i = 0; i < n; ++i) sum += _atoi(in[i]);
//     mx = max(mx, sum);
//   } while (next_permutation(a + 1, a + k));
//   return !printf("%d\n", mx);
// }
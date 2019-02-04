// #include <cstdio>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int n, m, a[305], psum[305], res[305], mn = 0x7f7f7f7f;

// bool solve(int prev, int remain, int ub) {
//   if (remain == 1) {
//     if (psum[n] - psum[prev] <= ub) {
//       res[m-1] = n - prev;
//       return true;
//     }
//     return false;
//   }

//   int i = n;
//   bool possible = false;
//   while (psum[i] - psum[prev] > ub) --i;
//   for (; i > prev; --i) {
//     possible = solve(i, remain - 1, ub);
//     if (possible) {
//       res[m - remain] = i - prev;
//       break;
//     }
//   }
//   return possible;
// }

// int main(int argc, char *argv[]) {
//   int i;
//   scanf("%d %d", &n, &m);
//   for (i = 1; i <= n; ++i) {
//     scanf("%d", a + i);
//     psum[i] = psum[i-1] + a[i];
//   }

//   int l = 1, r = 30000, mid;
//   while (l <= r) {
//     mid = (l + r) / 2;
//     bool isPossible = solve(0, m, mid);
//     if (isPossible) {
//       r = mid - 1;
//       mn = min(mn, mid);
//     } else {
//       l = mid + 1;
//     }
//   }

//   printf("%d\n", mn);
//   for (i = 0; i < m; ++i) printf("%d ", res[i]);
//   return !printf("\n");
// }

#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 300;
int n, m, a[MAX + 1], psum[MAX + 1], tmp[MAX], res[MAX];

bool solve(int prev, int remain, int upper_bound) {
  if (remain == 1) {
    if (psum[n] - psum[prev] <= upper_bound) {
      tmp[m-1] = n - prev;
      for (int i = 0; i < m; ++i) res[i] = tmp[i];
      return true;
    } else return false;
  }

  int idx = prev + 1;
  while (idx + remain - 1 < n && psum[idx] - psum[prev] <= upper_bound) ++idx;
  if (psum[idx] - psum[prev] > upper_bound) --idx;
  tmp[m - remain] = idx - prev;
  if (solve(idx, remain - 1, upper_bound)) return true;
  return false;
}

int main(int argc, char *argv[]) {
  int s = 0, e = 0, mid;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    s = max(s, a[i]);
    psum[i] = psum[i-1] + a[i];
  }
  
  e = psum[n] + 1;
  while (s < e) {
    mid = (s + e) >> 1;
    if (solve(0, m, mid)) e = mid;
    else s = mid + 1;
  }
  printf("%d\n", solve(0, m, s) ? s : s + 1);
  for (int i = 0; i < m; ++i) printf("%d ", res[i]);
  return !printf("\n");
}
// #include <cstdio>
// #include <cstring>
// #define INF 0x7f7f7f7f
// using namespace std;

// int color[205], dp[205], last[21]; 
// int main() {
//     int n, k, i, cnt = 0;
//     scanf("%d %d", &n, &k);
//     for (i = 0, cnt = 0; i < n; ++i) {
//         scanf("%d", color + cnt);
//         if (!cnt || (color[cnt-1] != color[cnt])) ++cnt;
//     }
//     n = cnt;
//     memset(last, 0x7f, sizeof(last));
//     for (i = n - 1; i >= 0; --i) {
//         int tmp = color[i];
//         color[i] = last[tmp];
//         last[tmp] = i;
//     }
//     for (i = 0; i < n - 1; ++i) {
//         if (color[i] == INF) dp[i+1] = dp[i] + 1;
//         else if (color[i+1] == INF) dp[i+1] = dp[i];
//         else if (color[i] > color[i+1]) dp[i+1] = dp[i];
//         else dp[i+1] = dp[i] + 1;
//     }
//     for (i = 0; i < n; ++i) printf("%d ", dp[i]);
//     puts("");
//     return !printf("%d\n", dp[n-1]);
// }

// #include <cstdio>
// #include <algorithm>
// using namespace std;

// int color[205], dp[205][21];
// int main(int argc, char *argv[]) {
//   int n, k, i, j, cnt = 0;
//   scanf("%d %d", &n, &k);
//   for (i = 0, cnt = 0; i < n; ++i) {
//       scanf("%d", color + cnt);
//       if (!cnt || (color[cnt-1] != color[cnt])) ++cnt;
//   }
//   n = cnt;
//   for (j = 1; j <= k; ++j) dp[0][j] = (color[0] == j ? 0 : 1);
//   for (i = 1; i < n; ++i) {
//     for (j = 1; j <= k; ++j) {
//       int offset = (color[i] == j ? 0 : 1);
//       dp[i][j] = min(dp[i-1][color[i]] + offset, dp[i-1][j] + offset);
//     }
//   }
//   for (j = 1; j <= k; ++j) {
//     printf("color %d : ", j);
//     for (i = 0; i < n; ++i) {
//       printf("%d ", dp[i][j]);
//     }
//     printf("\n");
//   }

//   int mn = 1e9;
//   for (j = 1; j <= k; ++j) mn = min(mn, dp[n-1][j]);
//   return !printf("%d\n", mn);
// }

// #include <cstdio>
// #include <vector>
// #include <algorithm>
// #define INF 0x7f7f7f7f
// using namespace std;

// int n, k, color[205], dp[205][21];
// bool chk[21];

// int main(int argc, char *argv[]) {
//   int i, cnt, h;
//   scanf("%d %d", &n, &k);
//   for (i = 0, cnt = 0; i < n; ++i) {
//       scanf("%d", color + cnt);
//       if (!cnt || (color[cnt-1] != color[cnt])) ++cnt;
//   }
//   n = cnt, h = 0;
//   vector <int> stack;
//   for (i = 0; i < n; ++i) {
    
//   }
//   return 0;
// }
    

#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x7f7f7f7f
using namespace std;

int color[205], dp[205][205];

int solve(int s, int e) {
  if (s == e) return 0;

  int &ret = dp[s][e];
  if (~ret) return ret;
  ret = INF;
  for (int k = s; k < e; ++k) {
    int offset = (color[s] == color[k+1] ? 0 : 1);
    ret = min(ret, solve(s, k) + solve(k+1, e) + offset);
  }
  return ret;
}

int main(int argc, char *argv[]) {
  int n, k, i, cnt;
  scanf("%d %d", &n, &k);
  for (i = 0, cnt = 0; i < n; ++i) {
      scanf("%d", color + cnt);
      if (!cnt || (color[cnt-1] != color[cnt])) ++cnt;
  }
  memset(dp, -1, sizeof(dp));
  return !printf("%d\n", solve(0, cnt-1));
}
// #include <cstdio>
// #include <cstring>
// #include <algorithm>
// #include <vector>
// #include <queue>
// #include <map>
// #define INF 1023456789LL
// #define MOD 1000000007LL
// using namespace std;

// typedef long long ll;
// typedef double db;

// char in[300050];
// int main(int argc, char *argv[]) {
//   int n, i, j, cnt[3] = {0};
//   scanf("%d", &n);
//   scanf(" %s", in);
//   for (i = 0; i < n; ++i) ++cnt[in[i] - '0'];
//   for (i = 0; i < 3; ++i) cnt[i] -= n/3;
//   if (cnt[2] > 0) {
//     for (i = 0; cnt[2] > 0 && cnt[0] < 0; ++i) {
//       if (in[i] == '2') {
//         in[i] = '0';
//         --cnt[2]; ++cnt[0];
//       }
//     }
//     for (; cnt[2] > 0 && cnt[1] < 0; ++i) {
//       if (in[i] == '2') {
//         in[i] = '1';
//         --cnt[2]; ++cnt[1];
//       }
//     }
//   }
//   if (cnt[0] > 0) {
//     for (i = n - 1; cnt[0] > 0 && cnt[2] < 0; --i) {
//       if (in[i] == '0') {
//         in[i] = '2';
//         --cnt[0]; ++cnt[2];
//       }
//     }
//     for (; cnt[0] > 0 && cnt[1] < 0; --i) {
//       if (in[i] == '0') {
//         in[i] = '1';
//         --cnt[0]; ++cnt[1];
//       }
//     }
//   }
//   if (cnt[1] > 0) {
//     for (i = 0; cnt[1] > 0 && cnt[0] < 0; ++i) {
//       if (in[i] == '1') {
//         in[i] = '0';
//         --cnt[1]; ++cnt[0];
//       }
//     }
//     for (i = n-1; cnt[1] > 0 && cnt[2] < 0; --i) {
//       if (in[i] == '1') {
//         in[i] = '2';
//         --cnt[1]; ++cnt[2];
//       }
//     }
//   } 
  
//   return !printf("%s\n", in);
// }

#include <cstdio>
#include <cstring>
using namespace std;

char in[300050];
int main(int argc, char *argv[]) {
  int n, i, j, c[3] = {0};
  scanf("%d\n%s", &n, in);
  for (i = 0; i < 3; ++i) c[i] -= n/3;
  for (i = 0; i < n; ++i) ++c[in[i] - '0'];
  for (i = 0; i < n; ++i) {
    if (c[in[i] - '0'] > 0) {
      for (j = '0'; j < in[i]; ++j) {
        if (c[j - '0'] < 0) {
          c[in[i] - '0']--; 
          c[j - '0']++;
          in[i] = j;
          break;
        }
      }
    }
  }
  for (i = n-1; i >= 0; --i) {
    if (c[in[i] - '0'] > 0) {
      for (j = '2'; j > in[i]; --j) {
        if (c[j - '0'] < 0) {
          c[in[i] - '0']--;
          c[j - '0']++;
          in[i] = j;
          break;
        }
      }
    }
  }
  return !printf("%s\n", in);
}
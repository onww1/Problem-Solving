// #include <cstdio>
// #include <cstring>
// #include <algorithm>
// using namespace std;

// struct segment {
//   int l, r;
// };

// bool cmp(segment a, segment b) {
//   if (a.r == b.r) return a.l < b.l;
//   return a.r < b.r;
// }

// segment segs[1005];
// int main(int argc, char *argv[]) {
//   int t, n, m, a, b, i, j;
//   scanf("%d", &t);
//   while (t--) {
//     scanf("%d %d", &n, &m);
//     for (i = 0; i < m; ++i) {
//       scanf("%d %d", &a, &b);
//       segs[i] = {a, b};
//     }
//     sort(segs, segs + m, cmp);

//     int cnt = 0;
//     bool visited[1005] = {};
//     for (i = 0; i < m; ++i) {
//       for (j = segs[i].l; j <= segs[i].r; ++j) {
//         if (!visited[j]) {
//           visited[j] = true;
//           ++cnt;
//           break;
//         }
//       }
//     }
//     printf("%d\n", cnt);
//   }
//   return 0;
// }

#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

struct segment {
  int l, r;
};

bool cmp(segment a, segment b) {
  if (a.l == b.l) return a.r < b.r;
  return a.l < b.l;
}

segment segs[1005];
int main(int argc, char *argv[]) {
  int t, n, m, a, b, i;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &m);
    for (i = 0; i < m; ++i) 
      scanf("%d %d", &segs[i].l, &segs[i].r);
    sort(segs, segs + m, cmp);
    priority_queue < int, vector<int>, greater<int> > pq;

    int cnt = 0, j = 0;
    for (i = 1; i <= n; ++i) {
      while (j < m && segs[j].l == i) 
        pq.push(segs[j++].r);
      while (!pq.empty() && pq.top() < i)
        pq.pop();
      if (!pq.empty()) {
        pq.pop();
        ++cnt;
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
}
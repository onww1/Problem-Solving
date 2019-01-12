#include <cstdio>
#include <algorithm>
using namespace std;

struct seg {
  int l, r, i, s;
};

bool cmp(seg a, seg b) {
  if (a.l == b.l) return a.r < b.r;
  return a.l < b.l;
}

bool cmp_idx(seg a, seg b) {
  return a.i < b.i;
}

seg segs[100050];
int main(int argc, char *argv[]) {
  int t, n, l, r, i, j, rm = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
      scanf("%d %d", &l, &r);
      segs[i] = {l, r, i, 0};
    }
    sort(segs, segs + n, cmp);
    rm = segs[0].r;
    for (i = 1; i < n; ++i) {
      if (segs[i].l <= rm) {
        rm = max(rm, segs[i].r);
      } else break;
    }
    if (i == n) {
      printf("-1\n");
      continue;
    }
    else {
      for (j = 0; j < i; ++j) segs[j].s = 1;
      for (j = i; j < n; ++j) segs[j].s = 2;
    }
    sort(segs, segs + n, cmp_idx);
    for (i = 0; i < n; ++i) printf("%d ", segs[i].s);
    printf("\n");
  }
  return 0;
}
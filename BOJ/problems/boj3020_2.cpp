#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 1e5, HMAX = 5e5;
int A[MAX + 1], B[MAX + 1], n, h;

int main(int argc, char *argv[]) {
  int i, a;
  scanf("%d %d", &n, &h);
  for (i = 0; i < n; ++i) {
    scanf("%d", &a);
    if (i & 1) A[i/2] = a;
    else B[i/2] = a;
  }
  n /= 2;
  sort(A, A + n);
  sort(B, B + n);

  int cnt = 0, mn = 2e9, mn_cnt = 0;
  for (i = 1; i <= h; ++i) {
    cnt = lower_bound(A, A + n, i) - A;
    cnt += lower_bound(B, B + n, h - i + 1) - B;
    if (mn > 2 * n - cnt) { 
      mn = 2 * n - cnt;
      mn_cnt = 1; 
    } else if (mn == 2 * n - cnt) mn_cnt++;
  }

  return !printf("%d %d\n", mn, mn_cnt);
}
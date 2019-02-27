#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

void hanoi(int n, int from, int mid, int to) {
  if (n == 0) return;
  hanoi(n - 1, from, to, mid);
  printf("%d %d\n", from, to);
  hanoi(n - 1, mid, from, to);
}

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);

  long long ans[2] = {1, 0};
  for (int i = 1; i <= n; ++i) {
    ans[1] *= 2LL;
    ans[0] *= 2LL;
    if (ans[0] > 1000000000000000LL) {
      ans[1] += (ans[0] / 1000000000000000LL);
      ans[0] %= 1000000000000000LL;
    }
  }

  if (ans[1]) printf("%lld%015lld\n", ans[1], ans[0] - 1);
  else printf("%lld\n", ans[0] - 1);

  if (n <= 20) hanoi(n, 1, 2, 3);
  return 0;
}
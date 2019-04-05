#include <cstdio>
using namespace std;

long long solve(int ub, int c[], int n) {
  long long sum = 0LL;
  for (int i=0; i<n; ++i) {
    if (c[i] > ub) sum += (long long)ub;
    else sum += (long long)c[i];
  }
  return sum;
}

int main(int argc, char *argv[]) {
  int n, c[10000];
  long long tot;
  scanf("%d", &n);
  for (int i=0; i<n; ++i) scanf("%d", &c[i]);
  scanf("%lld", &tot);

  int left = -1, right = 400000001, mid;
  long long sum;
  while (left + 1 < right) {
    mid = (left + right) / 2;
    sum = solve(mid, c, n);
    if (sum > tot) {
      right = mid;
    } else {
      left = mid;
    }
  }

  if (sum > tot) --mid;
  int max = 0;
  for (int i=0; i<n; ++i) {
    if (c[i] >= mid) {
      max = mid; 
      break;
    }
    else max = c[i] > max ? c[i] : max;
  }

  printf("%d\n", max);
  return 0;
}
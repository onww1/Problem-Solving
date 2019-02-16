#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1e5;
int A[MAX + 1], last[MAX + 1], N;
long long ans;

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) scanf("%d", A + i);

  int start = 0;
  for (int i = 1; i <= N; ++i) {
    if (last[A[i]] > start) start = last[A[i]];
    ans += (i - start);
    last[A[i]] = i;
  }

  return !printf("%lld\n", ans);
}
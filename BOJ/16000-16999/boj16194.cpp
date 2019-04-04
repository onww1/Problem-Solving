#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 10000;

int DP[MAX + 1], n, p; 
int main(int argc, char *argv[]) {
  int i, j;
  scanf("%d", &n);
  memset(DP, 0x7f, sizeof(DP));
  DP[0] = 0;
  for (i = 1; i <= n; ++i) {
    scanf("%d", &p);
    DP[i] = min(DP[i], p);
    for (j = 0; j + i <= n; ++j) 
      DP[j + i] = min(DP[j + i], DP[j] + p);
  }
  return !printf("%d\n", DP[n]);
}
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAX = 1e5;
int factor[MAX + 1] = { 0, 1 };

int n, k;
int main(int argc, char *argv[]) {
  
  for (int i = 2; i <= MAX; ++i) {
    if (!factor[i]) {
      for (int j = i; j <= MAX; j += i) factor[j] = i;
    }
  }

  scanf("%d %d", &n, &k);

  int cnt = 0;
  for (int i = 1; i <= n; ++i) if (factor[i] <= k) ++cnt;
  return !printf("%d\n", cnt);
}
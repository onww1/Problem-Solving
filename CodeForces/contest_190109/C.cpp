#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#define INF 1023456789LL
#define MOD 1000000007LL
using namespace std;

typedef long long ll;
typedef double db;

int in[105];
int main(int argc, char *argv[]) {
  int n, x, y, i, j, cnt = 0;
  scanf("%d %d %d", &n, &x, &y);
  for (i = 0; i < n; ++i) {
    scanf("%d", &in[i]);
    if (in[i] <= x) ++cnt;
  }
  if (x > y) return !printf("%d\n", n);
  else return !printf("%d\n", (cnt + 1) / 2);
}

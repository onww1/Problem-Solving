#include <cstdio>
using namespace std;
typedef long long ll;

const int MAX = 1e6;
int xcnt[MAX + 1], ycnt[MAX + 1];
bool noPrime[MAX + 1] = { true, true, };

int main(int argc, char *argv[]) {
  for (int i = 2; i < MAX; ++i) {
    if (noPrime[i]) {
      xcnt[i] = xcnt[i-1];
      ycnt[i] = ycnt[i-1];
      continue;
    }
    xcnt[i] = xcnt[i-1] + 1;
    ycnt[i] = ycnt[i-1] + (i == 2 || (i - 1) % 4 == 0 ? 1 : 0);
    for (ll j = (ll)i * i; j < MAX; j += i) noPrime[j] = true; 
  }

  for (int x, y; scanf("%d %d", &x, &y), x != -1 || y != -1;) {
    printf("%d %d ", x, y);
    if (y <= 0) x = y = 1;
    else if (x <= 0) x = 1;
    printf("%d %d\n", xcnt[y] - xcnt[x-1], ycnt[y] - ycnt[x-1]);
  }
  return 0;
}
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define X first
#define Y second
using namespace std;
typedef pair<long long, long long> pll;

int T, N, P[21];
pll point[21];
long double mn = 3000000.0;

int main(int argc, char *argv[]) {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    mn = 3000000.0;
    for (int i = 0; i < N; ++i) {
      scanf("%lld %lld", &point[i].X, &point[i].Y);
      P[i] = (i * 2 < N ? 0 : 1);
    }
    
    do {
      pll res = {0, 0};
      for (int i = 0; i < N; ++i) {
        if (P[i]) {
          res.X += point[i].X;
          res.Y += point[i].Y;
        } else {
          res.X -= point[i].X;
          res.Y -= point[i].Y;
        }
      }
      mn = min(mn, (long double)sqrt(res.X * res.X + res.Y * res.Y));
    } while (next_permutation(P, P + N));

    printf("%.12Lf\n", mn);
  }
  return 0;
}
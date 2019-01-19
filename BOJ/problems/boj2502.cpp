#include <cstdio>
using namespace std;

int main(int argc, char *argv[]) {
  int d, k, i, fibo[30] = {0, 1, 1, };
  scanf("%d %d", &d, &k);
  for (i = 3; i < d; ++i) fibo[i] = fibo[i-1] + fibo[i-2];
  for (i = k / fibo[d-1]; i > 0; --i) {
    if ((k - fibo[d-1] * i) % fibo[d-2] == 0) {
      return !printf("%d\n%d\n", (k - fibo[d-1] * i) / fibo[d-2], i);
    }
  }
  return !printf("-1\n");
}
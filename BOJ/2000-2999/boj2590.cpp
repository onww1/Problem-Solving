#include <cstdio>
using namespace std;

int main(int argc, char *argv[]) {
  int in[7], i, cnt = 0;
  for (i = 1; i < 7; ++i) scanf("%d", in + i);
  cnt = in[6];
  if (in[5]) {
    cnt += in[5];
    in[1] -= 11 * in[5];
  }
  if (in[4]) {
    cnt += in[4];
    in[2] -= 5 * in[4];
    if (in[2] < 0) in[1] += 4 * in[2], in[2] = 0;
  }
  if (in[3]) {
    cnt += (in[3] / 4 + (in[3] % 4 > 0 ? 1 : 0));
    if (in[3] % 4) {
      in[2] -= (7 - 2 * (in[3] % 4));
      in[1] -= (8 - (in[3] % 4));
      if (in[2] < 0) in[1] += 4 * in[2], in[2] = 0;
    }
  }
  int tmp = (in[2] > 0 ? in[2] * 4 : 0) + (in[1] > 0 ? in[1] : 0);
  cnt += (tmp / 36 + (tmp % 36 > 0 ? 1 : 0));
  return !printf("%d\n", cnt);
}
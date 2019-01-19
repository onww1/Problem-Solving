#include <cstdio>
using namespace std;

int main(int argc, char *argv[]) {
  int n, i, cnt[2] = {0};
  char in[16];
  scanf("%d %s", &n, in);
  for (i = 0; i < n; ++i) ++cnt[in[i] - 'A'];
  return !printf("%s\n", cnt[0] > cnt[1] ? "A" : cnt[0] < cnt[1] ? "B" : "Tie");
}
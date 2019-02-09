#include <cstdio>
#include <cstring>

char in[101], res[40];
int main(int argc, char *argv[]) {
  scanf("%s", in);
  int len = strlen(in), p = 0, idx = len % 3, val = 0;
  if (idx) {
    for (int i = 0; i < idx; ++i) val = val * 2 + in[i] - '0';
    res[p++] = val + '0';
  }
  for (; idx < len; idx += 3) {
    val = 0;
    for (int i = idx; i < idx + 3; ++i) val = val * 2 + in[i] - '0';
    res[p++] = val + '0';
  }
  res[p] = 0;
  return !printf("%s\n", res);
}
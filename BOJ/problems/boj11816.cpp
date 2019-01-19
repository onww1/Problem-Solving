#include <cstdio>
#include <cstring>
using namespace std;

char in[20];

int char_to_int(char c) {
  if ('0' <= c && c <= '9') return c - '0';
  return c - 'a' + 10;
}

int parse(char *str, int base) {
  int len = strlen(str), ret = 0;
  for (int i = 0; i < len; ++i) 
    ret = ret * base + char_to_int(str[i]);
  return ret;
}

int main(int argc, char *argv[]) {
  scanf("%s", in);
  int len = strlen(in), ans;
  if (in[0] == '0') {
    if (len == 1) ans = 0;
    else if (in[1] == 'x') ans = parse(in + 2, 16);
    else ans = parse(in + 1, 8);
  } else ans = parse(in, 10);
  return !printf("%d\n", ans);
}
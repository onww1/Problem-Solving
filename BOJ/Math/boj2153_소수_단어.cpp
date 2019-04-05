#include <cstdio>
#include <cstring>

char in[21];
int main(int argc, char *argv[]) {
  int len, i, s = 0;
  scanf("%s", in);
  len = strlen(in);
  for (i = 0; i < len; ++i) s += (in[i] <= 'Z' ? in[i] - 'A' + 27 : in[i] - 'a' + 1);
  for (i = 2; i * i <= s; ++i) {
    if (s % i == 0) return !printf("It is not a prime word.\n");
  }
  return !printf("It is a prime word.\n");
}
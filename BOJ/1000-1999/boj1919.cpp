#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char in[1005];
int c1[26], c2[26];
int main(int argc, char *argv[]) {
  int i, len, cnt = 0;
  scanf(" %s", in);
  len = strlen(in);
  for (i = 0; i < len; ++i) c1[in[i] - 'a']++;
  scanf(" %s", in);
  len = strlen(in);
  for (i = 0; i < len; ++i) c2[in[i] - 'a']++;
  for (i = 0; i < 26; ++i) cnt += abs(c1[i] - c2[i]);
  return !printf("%d\n", cnt);
}
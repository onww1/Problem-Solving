#include <cstdio>
#include <algorithm>
using namespace std;

char in[5][3]; int cnt[13];
int get_idx(char c) { 
  if ('2' <= c && c <= '9') return c - '1'; 
  else if (c == 'A') return 0;
  else if (c == 'T') return 9;
  else if (c == 'J') return 10;
  else if (c == 'Q') return 11;
  else if (c == 'K') return 12;
  return -1;
}
int main(int argc, char *argv[]) {
  int mx = 1;
  for (int i = 0; i < 5; ++i) {
    scanf(" %s", in[i]);
    cnt[get_idx(in[i][0])]++;
    mx = max(mx, cnt[get_idx(in[i][0])]);
  }
  return !printf("%d\n", mx);
}
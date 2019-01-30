#include <cstdio>
#include <cstring>
#include <algorithm>
#define X first
#define Y second
using namespace std;

struct str {
  char s[105];
  str() { s[0] = 0; }
};

typedef pair<str, int> psi;
bool cmp(psi a, psi b) { return strcmp(a.X.s, b.X.s) < 0; }

psi first[1005];
int shift[1005];
int main(int argc, char *argv[]) {
  char in[105];
  int t, n, i;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
      scanf(" %s", first[i].X.s);
      first[i].Y = i;
    }
    sort(first, first + n, cmp);
    for (i = 0; i < n; ++i) {
      scanf(" %s", in);
      int s = 0, e = n, m, r;
      while (s < e) {
        m = (s + e) / 2;
        r = strcmp(first[m].X.s, in);
        if (r == 0) {
          shift[first[m].Y] = i;
          break;
        }
        else if (r > 0) e = m;
        else s = m + 1; 
      }
    }

    for (i = 0; i < n; ++i) 
      scanf(" %s", first[i].X.s);
    for (i = 0; i < n; ++i)
      printf("%s ", first[shift[i]].X.s);
    printf("\n");
  }
  return 0;
}
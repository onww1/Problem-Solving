#include <cstdio>
using namespace std;

char pal[2001][2001];
int a[2001];

bool palindrome(int S, int E) {
  if (S == E) return true;
  else if (S + 1 == E) return a[S] == a[E];

  char &ret = pal[S][E];
  if (ret) return ret > 0;
  ret = (a[S] == a[E] ? 1 : -1);
  if (ret > 0) {
    ret = palindrome(S+1, E-1) ? 1 : -1;
  }
  return ret > 0;
}

int main(int argc, char *argv[]) {
  int n, m, s, e;
  scanf("%d", &n);
  for (int i=1; i<=n; ++i) scanf("%d", a + i);
  scanf("%d", &m);
  for (int i=0; i<m; ++i) {
    scanf("%d %d", &s, &e);
    printf("%d\n", palindrome(s, e) ? 1 : 0);
  }
  return 0;
}
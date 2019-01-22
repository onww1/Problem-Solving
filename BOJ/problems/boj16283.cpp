#include <cstdio>
using namespace std;

void swap(int &a, int &b) { int tmp = a; a = b; b = tmp; }

int main(int argc, char *argv[]) {
  int a, b, n, w, i, flg = 1;
  scanf("%d %d %d %d", &a, &b, &n, &w);
  if (a < b) swap(a, b), flg = 0;
  if (a == b) {
    if (w/a != n || n > 2) return !printf("-1\n"); 
    else return !printf("%d %d\n", 1, 1);
  } else {
    if ( (w - b * n) % (a - b) ) return !printf("-1\n");
    else {
      int x = (w - b * n) / (a - b);
      if (x == n || x == 0) return !printf("-1\n");
      return !printf("%d %d\n", flg ? x : n - x, flg ? n - x : x);
    }
  }
  return !printf("-1\n");
}

x + y = n
ax + by = w
y = n - x
ax + b(n-x) = w
(a-b)x = w - bn
x = (w-bn)/(a-b)
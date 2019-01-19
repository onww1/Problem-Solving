#include <cstdio>
using namespace std;

void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

int in[101];
int main(int argc, char *argv[]) {
  int n, m, a, b, i;
  scanf("%d %d", &n, &m);
  for (i = 1; i <= n; ++i) in[i] = i;
  for (i = 0; i < m; ++i) {
    scanf("%d %d", &a, &b);
    swap(in[a], in[b]);
  }
  for (i = 1; i <= n; ++i) printf("%d ", in[i]);
  return !printf("\n");
}
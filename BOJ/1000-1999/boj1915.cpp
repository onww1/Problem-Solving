#include <cstdio>
using namespace std;

int get_max(int a, int b) { return a > b ? a : b; }
int get_min(int a, int b) { return a < b ? a : b; }
int get_min(int a, int b, int c) { return get_min(get_min(a, b), c); }

int main(int argc, char *argv[]) {
  char input[1000][1001];
  int n, m, a[1000][1000], max = 0;
  scanf("%d %d", &n, &m);
  for (int i=0; i<n; ++i) {
    scanf("%s", input[i]);
    for (int j=0; j<m; ++j) {
      a[i][j] = input[i][j] - '0';   
      if (a[i][j]) max = 1;
    }
  }
  
  for (int i=1; i<n; ++i) {
    for (int j=1; j<m; ++j) {
      if (a[i][j]) {
        a[i][j] = get_min(a[i-1][j], a[i-1][j-1], a[i][j-1]) + 1;
        max = get_max(max, a[i][j]);
      }
    }
  }
  
  printf("%d\n", max * max);
  return 0;
}
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 5;

int arr[MAX];
int main(int argc, char *argv[]) {
  int a, b, n, i;
  scanf("%d %d %d", &a, &b, &n);
  for (i = 0; i < n; ++i) scanf("%d", arr + i);

  int mn = abs(b - a);
  for (i = 0; i < n; ++i) mn = min(mn, 1 + abs(arr[i] - b));
  return !printf("%d\n", mn);
}
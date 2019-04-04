#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
const int MAX = 2e5;

map <int,pii> mp;
int arr[MAX + 1];
int main(int argc, char *argv[]) {
  int a, n, mx = 0, mx_val = -1, i;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) {
    scanf("%d", &a);
    arr[i] = a;
    pii &f = mp[a-1], &s = mp[a];
    if (!f.first && !s.first) s = {1, i};
    else if (s.first < f.first + 1) s = {f.first + 1, i};
    if (mx < s.first) mx = s.first, mx_val = a;
  }
  printf("%d\n", mx);
  for (int i = 1, j = mx_val - mx + 1; i <= n && mx; ++i) {
    if (arr[i] == j) printf("%d ", i), ++j, --mx;
  }
  return !printf("\n");
}
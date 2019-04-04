#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#define INF 1023456789
#define MOD 1000000007
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

char in[1050], cnt[2];
int main(int argc, char *argv[]) {
  int n, i, j, k, flg;
  scanf("%s", in);
  n = strlen(in);
  for (i = 0; i < n; ++i) cnt[in[i] - '0']++;
  int flg1 = false, flg2 = false;
  for (i = 0; i < n; ++i) {
    if (in[i] == '0') {
      if (!flg1) printf("1 1\n"), flg1 = true;
      else printf("3 1\n"), flg1 = false;
    } else if (in[i] == '1') {
      if (!flg2) printf("3 3\n"), flg2 = true;
      else printf("3 1\n"), flg2 = false;
    }
  }
  return 0;
}
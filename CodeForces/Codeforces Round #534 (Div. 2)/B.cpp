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

char in[100050];
vector <char> stack;
int main(int argc, char *argv[]) {
  int n, i, j, cnt = 0;
  scanf("%s", in);
  n = strlen(in);
  for (i = 0; i < n; ++i) {
    if (stack.empty()) stack.push_back(in[i]);
    else if (stack.back() == in[i]) ++cnt, stack.pop_back();
    else stack.push_back(in[i]);
  }
  return !printf("%s\n", cnt % 2 ? "Yes" : "No");
}
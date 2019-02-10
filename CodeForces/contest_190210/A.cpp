#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;

const int MAX = 1e5;
const int INF = 0x7f7f7f7f;

int main(int argc, char *argv[]) {
  int x, y, z, a, b, c;
  scanf("%d %d %d %d %d %d", &x, &y, &z, &a, &b, &c);
  if (a >= x) a -= x; 
  else return !printf("NO\n");
  if (a + b >= y) y = (a+b) - y; 
  else return !printf("NO\n");
  if (y + c >= z) return !printf("YES\n");
  else return !printf("NO\n");
}
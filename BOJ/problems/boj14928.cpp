#include <cstdio>
#include <cstring>
using namespace std;

const int MOD = 20000303;
char in[1000010];

int main(int argc, char *argv[]) {
  int ans = 0;
  scanf("%s", in);
  for (int i = 0; in[i]; ++i) 
    ans = (ans * 10 + in[i] - '0') % MOD;
  return !printf("%d\n", ans);
}
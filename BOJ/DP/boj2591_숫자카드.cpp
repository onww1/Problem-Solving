#include <cstdio>
#include <cstring>
using namespace std;

char in[41];
int dp[41];

bool judge(int pos) {
  int num = (in[pos] - '0') * 10 + in[pos + 1] - '0';
  return (0 < num && num < 35);
}

int main(int argc, char *argv[]) {
  int i, j, len;
  scanf("%s", in);
  len = strlen(in);

  for (i = 0; i < len; ++i) {
    if (i) {
      if (in[i] > '0') dp[i] = dp[i-1];
      if (in[i-1] > '0' && judge(i-1)) dp[i] += (i-2 < 0 ? 1 : dp[i-2]);
    } else {
      if (in[i] > '0') dp[i] = 1;
    }
  }

  return !printf("%d\n", dp[len - 1]);
}
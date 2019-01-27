#include <cstdio>
#include <algorithm>
using namespace std;

int DP[1001]; 
int main(int argc, char *argv[]) {
  int n, i;
  scanf("%d", &n);
  DP[2] = DP[4] = 1;
  for (i = 5; i <= n; ++i) 
    DP[i] = min({DP[i-1], DP[i-3], DP[i-4]}) == 0 ? 1 : 0;
  return !printf("%s\n", DP[n] ? "SK" : "CY");
}

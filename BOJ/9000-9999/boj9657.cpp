#include <cstdio>
#include <algorithm>
using namespace std;

int DP[1001]; 
int main(int argc, char *argv[]) {
  int n, i;
  scanf("%d", &n);
  DP[2] = 1;
  for (i = 5; i <= n; ++i) 
    DP[i] = max({DP[i-1], DP[i-3], DP[i-4]}) ? 0 : 1;
  return !printf("%s\n", DP[n] ? "CY" : "SK");
}
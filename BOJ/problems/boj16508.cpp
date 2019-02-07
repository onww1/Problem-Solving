#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char alpha[17][26], in[51];
int c[17], n, i, j, k, mn = 1e9;

int main(int argc, char *argv[]) {
  scanf(" %s", in);
  for (i = 0; in[i]; ++i) alpha[0][in[i] - 'A']++;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) {
    scanf("%d %s", c + i, in);
    for (j = 0; in[j]; ++j) alpha[i][in[j] - 'A']++;
  }

  for (i = 1; i < (1 << n); ++i) {
    int sum = 0, cnt[26] = {0}; 
    for (j = 0; j < n; ++j) {
      if (i & (1 << j)) {
        sum += c[j + 1];
        for (k = 0; k < 26; ++k) cnt[k] += alpha[j + 1][k];
      }
    }
    
    for (k = 0; k < 26; ++k) 
      if (alpha[0][k] > cnt[k]) 
        break;
    
    if (k == 26) mn = min(mn, sum);
  }

  return !printf("%d\n", mn == 1e9 ? -1 : mn);
}
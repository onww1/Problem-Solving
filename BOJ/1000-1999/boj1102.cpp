#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 16;
const int INF = 0x7f7f7f7f;
int DP[1 << MAX], C[MAX][MAX], N, P;
char in[MAX + 1]; 

int solve(int state, int cnt) {
  if (cnt == P) return 0;

  int &ret = DP[state];
  if (ret != -1) return ret;
  ret = INF;

  for (int i = 0; i < N; ++i) {
    if (state & (1 << i)) continue;
    int mn = INF;
    for (int j = 0; j < N; ++j) if (state & (1 << j)) 
      mn = min(mn, C[j][i]);
    ret = min(ret, mn + solve(state | (1 << i), cnt + 1));
  }
  return ret;
}

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) scanf("%d", &C[i][j]);
  scanf(" %s %d", in, &P);

  int cnt = 0, state = 0;
  for (int i = 0; in[i]; ++i) 
    if (in[i] == 'Y') state |= (1 << i), ++cnt;
  
  if (P && !cnt) return !printf("-1\n");
  if (P <= cnt) return !printf("0\n");

  memset(DP, -1, sizeof(DP));
  return !printf("%d\n", solve(state, cnt));
}
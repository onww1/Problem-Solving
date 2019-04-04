#include <cstdio>
int N, M, MAP[5000][167];
char in[10005];
int main() {
  scanf("%d", &N);
  getchar();
  for (int i = 0; i < N; ++i) {
    fgets(in, sizeof(in), stdin);
    for (int j = 0; in[2 * j]; ++j) {
      if (in[2 * j] == '+') 
        MAP[i][j / 30] |= (1 << (j % 30));
    }
  }

  scanf("%d", &M);
  for (int i = 0, A, B; i < M; ++i) {
    scanf("%d %d", &A, &B);
    puts(MAP[A][B / 30] & (1 << (B % 30)) ? "+" : "-");
  }

  return 0;
}
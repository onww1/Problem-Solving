#include <cstdio>
#include <cstring>
#include <algorithm>
#define X first
#define Y second
using namespace std; 
typedef pair<int,int> pii;

int N, K, A[10][10];
int B[3][20], C[20];

bool solve();

int main(int argc, char *argv[]) {
  scanf("%d %d", &N, &K);
  for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j)
    scanf("%d", &A[i][j]);
  for (int i = 0; i < 20; ++i) scanf("%d", &B[1][i]);
  for (int i = 0; i < 20; ++i) scanf("%d", &B[2][i]);
  for (int i = 0; i < N; ++i) B[0][i] = i + 1;

  do {
    if (solve()) 
      return !printf("1\n");
  } while (next_permutation(B[0], B[0] + N));

  printf("0\n");
  return 0;
}

bool solve() {
  int win[3] = {}, idx[3] = {};
  pii turn = {0, 1};
  while (1) {
    int result = A[B[turn.X][idx[turn.X]++]][B[turn.Y][idx[turn.Y]++]];
    if (result == 2) {
      win[turn.X]++;
      turn = {min(turn.X, 3 - turn.X - turn.Y), max(turn.X, 3 - turn.X - turn.Y)};
    }
    else {
      win[turn.Y]++;
      turn = {min(turn.Y, 3 - turn.X - turn.Y), max(turn.Y, 3 - turn.X - turn.Y)};
    }

    if (win[0] == K) return true;
    else if (idx[0] == N || win[1] == K || win[2] == K) return false;
  }
}
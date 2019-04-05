#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;

vector <pii> vec;
char in[5][10];
bool visited[13];

bool solve(int T) {
  if (T == vec.size()) {
    if (in[0][4] + in[1][3] + in[2][2] + in[3][1] - 4 * ('A' - 1) != 26) return false;
    if (in[0][4] + in[1][5] + in[2][6] + in[3][7] - 4 * ('A' - 1) != 26) return false;
    if (in[1][1] + in[1][3] + in[1][5] + in[1][7] - 4 * ('A' - 1) != 26) return false;
    if (in[3][1] + in[3][3] + in[3][5] + in[3][7] - 4 * ('A' - 1) != 26) return false;
    if (in[4][4] + in[3][3] + in[2][2] + in[1][1] - 4 * ('A' - 1) != 26) return false;
    if (in[4][4] + in[3][5] + in[2][6] + in[1][7] - 4 * ('A' - 1) != 26) return false;
    return true;
  }

  for (int i = 1; i <= 12; ++i) {
    if (!visited[i]) {
      visited[i] = true;
      in[vec[T].first][vec[T].second] = 'A' + i - 1;
      if (solve(T+1)) return true;
      visited[i] = false;
      in[vec[T].first][vec[T].second] = 'x';
    }
  }
  return false;
}

int main(int argc, char *argv[]) {
  int i, j;
  for (i = 0; i < 5; ++i) {
    scanf(" %s", in[i]);
    for (j = 0; j < 9; ++j) {
      if (in[i][j] == 'x') vec.push_back({i, j});
      else if (in[i][j] != '.') visited[in[i][j] - 'A' + 1] = true;
    }
  }

  solve(0);

  for (i = 0; i < 5; ++i) printf("%s\n", in[i]);
  return 0;
}
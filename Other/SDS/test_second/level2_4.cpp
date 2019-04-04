#include <iostream>
#include <vector>
using namespace std;

int T, map[6][4], chk[6][4], status[6][4];
vector< vector< vector< vector<int> > > > puzzle(8);
vector< vector<int> > offset(8);

void init();
bool add(int row, int col, vector< vector<int> >& block, int val, int& sum);
void solve(int prev_r, int prev_c, int sum, int& max);

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  init();

  cin >> T;
  for (int test_case = 1; test_case <= T; ++test_case) {
    for (int i = 0; i < 6; ++i) 
      for (int j = 0; j < 4; ++j) {
        cin >> map[i][j];
        chk[i][j] = 0;
      }
    
    int max = 0;
    solve(0, -1, 0, max);
    cout << '#' << test_case << ' ' <<  max << '\n';
  }

  return 0;
}

void solve(int prev_r, int prev_c, int sum, int& max) {
  int i = prev_r, j = prev_c + 1;
  if (prev_c == 3) {
    i = prev_r + 1;
    j = 0;
  }

  while (!map[i][j] || chk[i][j]) {
    ++j;
    if (j == 4) {
      ++i;
      if (i == 6) {
        max = sum > max ? sum : max;
        return;
      }
      j = 0;
    }
  }

  for (int type = 0; type < 8; ++type) {
    for (int idx = 0; idx < puzzle[type].size(); ++idx) {
      if (j < offset[type][idx] || j - offset[type][idx] + puzzle[type][idx][0].size() > 4 || (i + puzzle[type][idx].size()) > 6) continue;
      if (add(i, j-offset[type][idx], puzzle[type][idx], 1, sum)) {
        solve(i, j, sum, max);
      } 
      add(i, j-offset[type][idx], puzzle[type][idx], -1, sum);
    }
  }  
}

bool add(int row, int col, vector< vector<int> >& block, int val, int &sum) {
  bool valid = true;
  for (int i = 0; i < block.size(); ++i) {
    for (int j = 0; j < block[i].size(); ++j) {
      if (block[i][j]) {
        if (!map[row + i][col + j] || chk[row + i][col + j]) valid = false;
        chk[row + i][col + j] += val;
        if (val > 0) status[row + i][col + j] += block[i][j];
        else if (val < 0) status[row + i][col + j] -= block[i][j];
        if (block[i][j] == map[row + i][col + j]) {
          if (val > 0) ++sum;
          else --sum;
        }
      }
    }
  }
  return valid;
}

void init() {
  puzzle[0].resize(8);
  puzzle[1].resize(4);
  puzzle[2].resize(4);
  puzzle[3].resize(1);
  puzzle[4].resize(4);
  puzzle[5].resize(4);
  puzzle[6].resize(8);
  puzzle[7].resize(4);

  offset[0].resize(8);
  offset[1].resize(4);
  offset[2].resize(4);
  offset[3].resize(1);
  offset[4].resize(4);
  offset[5].resize(4);
  offset[6].resize(8);
  offset[7].resize(4);

  puzzle[3][0].resize(2, vector<int>(2));
  for (int i = 0; i < 8; ++i) {
    if (i%2) {
      puzzle[0][i].resize(3, vector<int>(2));
      puzzle[6][i].resize(3, vector<int>(2));
    } else {
      puzzle[0][i].resize(2, vector<int>(3));
      puzzle[6][i].resize(2, vector<int>(3));
    }
  }
  for (int i = 0; i < 4; ++i) {
    puzzle[4][i].resize(3, vector<int>(3));
    puzzle[5][i].resize(3, vector<int>(3));
    puzzle[7][i].resize(3, vector<int>(3));

    if (i%2) {
      puzzle[1][i].resize(3, vector<int>(2));
      puzzle[2][i].resize(3, vector<int>(2));
    } else {
      puzzle[1][i].resize(2, vector<int>(3));
      puzzle[2][i].resize(2, vector<int>(3));
    }
  }
  
  puzzle[0][0] = {{0, 0, 1}, {1, 1 ,1}};
  puzzle[0][1] = {{1, 0}, {1, 0}, {1, 1}};
  puzzle[0][2] = {{1, 1, 1}, {1, 0, 0}};
  puzzle[0][3] = {{1, 1}, {0, 1}, {0, 1}};
  puzzle[0][4] = {{1, 0, 0}, {1, 1 ,1}};
  puzzle[0][5] = {{1, 1}, {1, 0}, {1, 0}};
  puzzle[0][6] = {{1, 1, 1}, {0, 0 ,1}};
  puzzle[0][7] = {{0, 1}, {0, 1}, {1, 1}};

  puzzle[1][0] = {{0, 2, 0}, {2, 2, 2}};
  puzzle[1][1] = {{2, 0}, {2, 2}, {2, 0}};
  puzzle[1][2] = {{2, 2, 2}, {0, 2, 0}};
  puzzle[1][3] = {{0, 2}, {2, 2}, {0, 2}};
  
  puzzle[2][0] = {{3, 3, 0}, {0, 3, 3}};
  puzzle[2][1] = {{0, 3}, {3, 3}, {3, 0}};
  puzzle[2][2] = {{0, 3, 3}, {3, 3, 0}};;
  puzzle[2][3] = {{3, 0}, {3, 3}, {0, 3}};;
  
  puzzle[3][0] = {{4, 4}, {4, 4}};

  puzzle[4][0] = {{0, 5, 5}, {0, 5, 0}, {5, 5, 0}};
  puzzle[4][1] = {{5, 0, 0}, {5, 5, 5}, {0, 0, 5}};
  puzzle[4][2] = {{5, 5, 0}, {0, 5, 0}, {0, 5, 5}};
  puzzle[4][3] = {{0, 0, 5}, {5, 5, 5}, {5, 0, 0}};

  puzzle[5][0] = {{0, 6, 0}, {0, 6, 0}, {6, 6, 6}};
  puzzle[5][1] = {{6, 0, 0}, {6, 6, 6}, {6, 0, 0}};
  puzzle[5][2] = {{6, 6, 6}, {0, 6, 0}, {0, 6, 0}};
  puzzle[5][3] = {{0, 0, 6}, {6, 6, 6}, {0, 0, 6}};

  puzzle[6][0] = {{7, 7, 0}, {7, 7, 7}};
  puzzle[6][1] = {{7, 7}, {7, 7}, {7, 0}};
  puzzle[6][2] = {{7, 7, 7}, {0, 7, 7}};
  puzzle[6][3] = {{0, 7}, {7, 7}, {7, 7}};
  puzzle[6][4] = {{0, 7, 7}, {7, 7, 7}};
  puzzle[6][5] = {{7, 0}, {7, 7}, {7, 7}};
  puzzle[6][6] = {{7, 7, 7}, {7, 7, 0}};
  puzzle[6][7] = {{7, 7}, {7, 7}, {0, 7}};

  puzzle[7][0] = {{0, 0, 8}, {0, 0, 8}, {8, 8, 8}};
  puzzle[7][1] = {{8, 0, 0}, {8, 0, 0}, {8, 8, 8}};
  puzzle[7][2] = {{8, 8, 8}, {8, 0, 0}, {8, 0, 0}};
  puzzle[7][3] = {{8, 8, 8}, {0, 0, 8}, {0, 0, 8}};

  for (int type = 0; type < 8; ++type) {
    for (int idx = 0; idx < puzzle[type].size(); ++idx) {
      int offset_val = 0;
      while (!puzzle[type][idx][0][offset_val]) ++offset_val;
      offset[type][idx] = offset_val;
    }
  }
}
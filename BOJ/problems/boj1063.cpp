#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;

const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int N;
pii K, S;
map <string, int> mp;

bool check(int r, int c) {
  return r >= 0 && r < 8 && c >= 0 && c < 8;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  string s;
  cin >> s; 
  K = { s[1] - '1', s[0] - 'A' }; // 킹의 위치
  cin >> s;
  S = { s[1] - '1', s[0] - 'A' }; // 돌의 위치
  cin >> N;

  mp["B"] = 0;
  mp["L"] = 1;
  mp["T"] = 2;
  mp["R"] = 3;
  mp["LB"] = 4;
  mp["RB"] = 5;
  mp["LT"] = 6;
  mp["RT"] = 7;

  for (int i = 0; i < N; ++i) {
    cin >> s;
    int cmd = mp[s];
    int dr = K.X + move_r[cmd], dc = K.Y + move_c[cmd];
    if (dr == S.X && dc == S.Y) {
      int sdr = S.X + move_r[cmd], sdc = S.Y + move_c[cmd];
      if (check(dr, dc) && check(sdr, sdc)) {
        K = { dr, dc };
        S = { sdr, sdc };
      }
    } else {
      if (check(dr, dc)) K = { dr, dc };
    }
  }

  printf("%c%c\n%c%c\n", K.Y + 'A', K.X + '1', S.Y + 'A', S.X + '1');
  return 0;
}
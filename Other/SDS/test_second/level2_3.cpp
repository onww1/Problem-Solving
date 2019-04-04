#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct point {
  int x, y, n;
};

bool cmp(point a, point b) {
  if (a.x == b.x) return a.y < b.y;
  return a.x < b.x;
}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int T, N, x, y;
  vector<point> pos;
  
  cin >> T;
  for (int test_case = 1; test_case <= T; ++test_case) {
    cin >> N;
    pos.clear();
    for (int i = 1; i <= N; ++i) {
      cin >> x >> y;
      pos.push_back({x, y, i});
    }

    sort(pos.begin(), pos.end(), cmp);

    int curX = pos[0].x, minY = pos[0].y;
    cout << '#' << test_case << ' ';
    cout << pos[0].n;

    int len = pos.size();
    for (int i = 1; i < len; ++i) {
      point &cur = pos[i];
      if (curX == cur.x) continue;
      else {
        curX = cur.x;
        if (cur.y < minY) {
          cout << ' ' << cur.n;
          minY = cur.y;
        }
      }
    }
    cout << '\n';
  }

  return 0;
}
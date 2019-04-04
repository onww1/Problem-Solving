#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

const int mov[] = {-3, 3, -1, 1};
const int move_r[] = {-1, 1, 0, 0};
const int move_c[] = {0, 0, -1, 1};

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string source = "", destination = "123456780";
  for (int i = 0; i < 9; ++i) {
    char c;
    cin >> c; 
    source += c;
  }

  set <string> visited;
  visited.insert(source);
  queue <string> q;
  q.push(source);

  int cnt = 0, size = 0;
  while (!q.empty()) {
    // 한 depth마다 size를 받아서 하면 횟수를 구할 수 있음.
    size = q.size();
    while (size--) {
      string current = q.front();
      q.pop();

      if (current == destination) {
        cout << cnt << '\n'; 
        return 0;
      }

      int pos = 0;
      for (; current[pos] != '0'; ++pos);

      int r = pos / 3, c = pos % 3;
      for (int k = 0; k < 4; ++k) {
        int dr = r + move_r[k];
        int dc = c + move_c[k];
        if (dr < 0 || dr >= 3 || dc < 0 || dc >= 3) continue;
        int next_pos = pos + mov[k];

        string next = current;
        swap(next[next_pos], next[pos]);
        if (visited.find(next) == visited.end()) {
          visited.insert(next);
          q.push(next);
        }
      }
    }
    cnt++;
  }

  cout << -1 << '\n';
  return 0;
}
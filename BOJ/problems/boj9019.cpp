#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#define MOD 10000
using namespace std;

struct info {
  string cmd;
  int val;
};

int cmds[10000];
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, a, b, i;
  cin >> n;
  while (n--) {
    cin >> a >> b;
    memset(cmds, 0x7f, sizeof(cmds));
    queue <info> q;
    q.push({"", a}); cmds[a] = 0;
    while (!q.empty()) {
      string cmd = q.front().cmd;
      int val = q.front().val;
      q.pop();

      if (val == b) {
        cout << cmd << '\n';
        break;
      }

      int twice = (val * 2) % MOD;
      if (cmds[twice] > cmd.size() + 1) {
        cmds[twice] = cmd.size() + 1;
        q.push({cmd + 'D', twice});
      }

      int minus = (val - 1 + MOD) % MOD;
      if (cmds[minus] > cmd.size() + 1) {
        cmds[minus] = cmd.size() + 1;
        q.push({cmd + 'S', minus});
      }
      
      int left = (val % 1000 * 10) + val / 1000;
      if (cmds[left] > cmd.size() + 1) {
        cmds[left] = cmd.size() + 1;
        q.push({cmd + 'L', left});
      }

      int right = (val / 10) + val % 10 * 1000;
      if (cmds[right] > cmd.size() + 1) {
        cmds[right] = cmd.size() + 1;
        q.push({cmd + 'R', right});
      }
    }
  }
  return 0;
}
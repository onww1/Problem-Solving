#include <cstdio>
#include <vector>
using namespace std;

struct hint { 
  int seq, s, b;
};

vector <hint> hints;
int ans = 0;

bool check(hint h, int seq) {
  int s = 0, b = 0;
  for (int i = 1; i <= 100; i *= 10) {
    for (int j = 1; j <= 100; j *= 10) {
      if ((seq / i % 10) == (h.seq / j % 10)) {
        if (i == j) ++s;
        else ++b;
      }
    }
  }
  if (s == h.s && b == h.b) return true;
  return false;
}

void solve(int seq, int T) {
  if (T == 3) {
    for (auto it : hints) {
      if (!check(it, seq)) return;
    }
    ++ans;
    return;
  }

  for (int i = 1; i <= 9; ++i) {
    if (T == 1 && seq == i) continue;
    else if (T == 2 && ((seq % 10) == i || (seq / 10 % 10) == i )) continue;
    solve(seq * 10 + i, T + 1);
  }
}

int main(int argc, char *argv[]) {
  int n, seq, s, b, i;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d %d %d", &seq, &s, &b);
    hints.push_back({seq, s, b});
  }
  solve(0, 0);
  return !printf("%d\n", ans);
}
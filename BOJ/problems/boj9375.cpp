#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int t, n, i, ans;  
  string name, type;

  cin >> t;
  while (t--) {
    map<string, int> m;
    cin >> n;
    for (i = 0; i < n; ++i) {
      cin >> name >> type;
      ++m[type];
    }

    ans = 1;
    for (auto it = m.begin(); it != m.end(); ++it) {
      ans *= (it->second + 1);
    }
    cout << (ans - 1) << '\n';
  }

  return 0;
}
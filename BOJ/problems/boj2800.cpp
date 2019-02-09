#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;

set <string> s;
pii paren[10];
string str;
int p = 0;

void solve(int visited, int prev) {
  if (prev != -1) {
    string tmp = str; vector <int> idx;
    for (int i = 0; i <= prev; ++i) {
      if (visited & (1 << i)) {
        idx.push_back(paren[i].first);
        idx.push_back(paren[i].second);
      }
    }
    sort(idx.begin(), idx.end());
    for (int i = idx.size() - 1; i >= 0; --i) tmp.erase(idx[i], 1);
    s.insert(tmp);
  }

  for (int i = prev + 1; i < p; ++i) 
    solve(visited | (1 << i), i);
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  cin >> str;
  vector <int> stack; 
  for (int i = 0; i < str.size(); ++i) {
    if (str[i] == '(') stack.push_back(i);
    else if (str[i] == ')') {
      paren[p++] = {stack.back(), i};
      stack.pop_back();
    }
  }

  solve(0, -1);
  for (string ss : s) cout << ss << '\n';
  return 0;
}

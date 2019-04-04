#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n;
  string str;
  vector<char> stack;

  cin >> n;
  cin >> str;

  if (n % 2) cout << 0 << '\n';
  else {
    for (int i=0; i<n; ++i) {
      if (str[i] == '(') stack.push_back('(');
      else stack.pop();
    }
  }



  return 0;
}
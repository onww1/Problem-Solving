#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  string str;
  cin >> str;

  int len = 1;
  for (int i=0; i<str.size(); i += len, ++len) {
    cout << str[i];
  }
  cout << '\n';

  return 0;
}
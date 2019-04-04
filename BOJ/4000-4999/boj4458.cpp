#include <iostream>
#include <string>
using namespace std;

char toUpper(char c) {
  if ('a' <= c && c <= 'z') return c - 'a' + 'A';
  return c;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int n, i;
  string in;
  cin >> n;
  getline(cin, in);
  for (i = 0; i < n; ++i) {
    getline(cin, in);
    in[0] = toUpper(in[0]);
    cout << in << '\n';
  }
  return 0;
}
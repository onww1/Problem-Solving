#include <iostream>
#include <string>
using namespace std;

bool isVowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
         c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

string in;
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int len, cnt, i;
  while (getline(cin, in)) {
    if (in == "#") break;
    len = in.size();
    cnt = 0;
    for (i = 0; i < len; ++i) if (isVowel(in[i])) ++cnt;
    cout << cnt << '\n';
  }
  return 0;
}
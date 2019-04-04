#include <iostream>
#include <deque>
using namespace std;

int getIndex(char c) {
  return c - 'A';
}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int T, N;
  char c;
  deque<char> dq;

  cin >> T;
  for (int test_case = 1; test_case <= T; ++test_case) {
    cin >> N;
    dq.clear();

    cin >> c;
    dq.push_back(c);
    for (int i=1; i<N; ++i) {
      cin >> c;
      if (getIndex(dq.front()) <= getIndex(c)) {
        dq.push_front(c);
      } else {
        dq.push_back(c);
      }
    }

    cout << '#' << test_case << ' ';
    for (auto &it : dq) {
      cout << it;
    }
    cout << '\n';
  }

  return 0;
}
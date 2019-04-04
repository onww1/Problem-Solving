#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#define INF 987654321
#define MOD 1000000007
using namespace std;

typedef long long ll;

int index(char c) {
  return c - 'A';
}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  string str;
  bool visited[100] = {false};

  cin >> str;
  int len = str.size();

  int min = 987654321, min_idx = -1, idx;
  for (int i=0; i<len; ++i) {
    idx = index(str[i]);
    if (min > idx) {
      min = idx;
      min_idx = i;
    }
  }
  visited[min_idx] = true;
  cout << str[min_idx] << '\n';

  for (int i=1; i<len; ++i) {
    int first = len-1;
    min_idx = -1, min = 987654321;
    while (visited[first]) --first;
    while (first >= 0 && !visited[first]) --first;
    for (int j=first + 1; j < len; ++j) {
      if (!visited[j]) {
        idx = index(str[j]);
        if (min > idx) {
          min = idx;
          min_idx = j;
        }
      } else break;
    }
    visited[min_idx] = true;
    for (int j=0; j<len; ++j) {
      if (visited[j]) cout << str[j];
    }
    cout << '\n';
  }

  return 0;
}

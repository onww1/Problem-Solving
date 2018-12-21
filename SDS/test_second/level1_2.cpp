#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int T, N, M, color[51], car[1000], tot;
  bool isTarget[51];
  cin >> T;
  for (int test_case = 1; test_case <= T; ++test_case) {
    cin >> N >> M;
    tot = 0;
    for (int i = 1; i <= M; ++i) {
      cin >> color[i];
      if (color[i]) isTarget[i] = true;
      else isTarget[i] = false;
      tot += color[i];
    }
    for (int i = 0; i < N; ++i) {
      cin >> car[i];
    }

    bool isFound = false;
    int left = 0, right = 0;
    while (right < N && left <= right) {
      if (isTarget[car[right]]) {
        if (color[car[right]]) {
          --tot;
          --color[car[right]];
          ++right;
          if (!tot) {
            isFound = true;
            break;
          }
        } else {
          while (car[left] != car[right]) {
            ++tot;
            ++color[car[left]];
            ++left;
          }
          ++left; ++right;
        }
      } else {
        while (left < right) {
          ++tot;
          ++color[car[left]];
          ++left;
        }
        ++left; ++right;
      }
    }

    cout << '#' << test_case << ' ';
    if (isFound) cout << (left + 1) << '\n';
    else cout << 0 << '\n';
  }

  return 0;
}
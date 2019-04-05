#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, H[1000], max = 0, first;

  cin >> N;
  for (int i=0; i<N; ++i) cin >> H[i];

  first = H[0];
  for (int i=1; i<N; ++i) {
    if (H[i] <= H[i-1]) {
      first = H[i];
    } else {
      max = H[i] - first > max ? H[i] - first : max;
    }
  }

  cout << max << '\n';
  return 0;
}
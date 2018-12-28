#include <iostream>
#include <vector>
using namespace std;

int get_min(int a, int b) { return a < b ? a : b;}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n, a[100000];
  int Max[2] = {0}, Min[2] = {987654321, 987654321};

  cin >> n;
  cin >> a[0];
  Max[0] = Max[1] = Min[0] = Min[1] = a[0];
  for (int i=1; i<n; ++i) {
    cin >> a[i];
    if (a[i] >= Max[0]) {
      Max[1] = Max[0];
      Max[0] = a[i];
    } else if (a[i] >= Max[1]) {
      Max[1] = a[i];
    }
    if (a[i] <= Min[0]) {
      Min[1] = Min[0];
      Min[0] = a[i];
    } else if (a[i] <= Min[1]) {
      Min[1] = a[i];
    }
  }
  
  cout << get_min(Max[0] - Min[1], Max[1] - Min[0]) << '\n';
  return 0;
}
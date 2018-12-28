#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n;
  int a[200001][2];

  cin >> n;
  for (int i=1; i<=n; ++i) {
    cin >> a[i][0] >> a[i][1];
  }

  vector<int> order;
  order.push_back(1);
  if (a[a[1][0]][0] == a[1][1] || a[a[1][0]][1] == a[1][1]) {
    order.push_back(a[1][0]);
    order.push_back(a[1][1]);
  } else {
    order.push_back(a[1][1]);
    order.push_back(a[1][0]);
  }

  int cur = order[1];
  while (1) {
    int back = order.back();
    if (a[cur][0] != back) {
      if (a[cur][0] == 1) break;
      order.push_back(a[cur][0]);
    } else {
      if (a[cur][1] == 1) break;
      order.push_back(a[cur][1]);
    }
    cur = back;
  }

  for (auto &it : order) {
    cout << it << ' ';
  }
  cout << '\n';
  return 0;
}

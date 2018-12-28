#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;

struct offer {
  int u, v;
  ll val;  
};

bool operator<(offer a, offer b) {
  return a.val > b.val;
}

ll a[200001];
ll len[200001];
ll sum;

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  int min_idx = 0;
  ll min = 1LL << 60;
  for (int i=1; i<=n; ++i) {
    cin >> a[i];
    if (a[i] < min) {
      min = a[i];
      min_idx = i;
    }
  }

  for (int i=1; i<=n; ++i) {
    if (i != min_idx) {
      sum += (a[i] + min);
      len[i] = a[i] + min;
    }
  }
  
  ll changed[200001] = {0LL};
  int x, y; ll w, max_val;
  for (int i=0; i<m; ++i) {
    cin >> x >> y >> w;
    if (changed[x] && changed[y]) {
      if (changed[x] > changed[y]) {
        if (changed[x] > w) {
          sum -= (changed[x] - w);
          changed[x] = w;
        }
      } else {
        if (changed[y] > w) {
          sum -= (changed[y] - w);
          changed[y] = w;
        }
      }
    }
    else if (changed[x]) {
      if (changed[x] > a[y] + min) {
        if (changed[x] > w) {
          sum -= (changed[x] - w);
          changed[x] = w;
        }
      } else {
        if (a[y] + min > w) {
          sum -= (a[y] + min - w);
          changed[y] = w;
        }
      }
    } 
    else if (changed[y]) {
      if (changed[y] > a[x] + min) {
        if (changed[y] > w) {
          sum -= (changed[y] - w);
          changed[y] = w;
        }
      } else {
        if (a[x] + min > w) {
          sum -= (a[x] + min - w);
          changed[x] = w;
        }
      }
    } 
    else {
      if (a[x] > a[y]) {
        if (a[x] + min > w) {
          sum -= (a[x] + min - w);
          changed[x] = w;
        }
      } else {
        if (y == min_idx) {
          if (a[x] + min + w) {
            sum -= (a[x] + min - w);
            changed[x] = w;
          }
        } else {
          if (a[y] + min > w) {
            sum -= (a[y] + min - w);
            changed[y] = w;
          }
        }
      }
    }
  }

  cout << sum << '\n';
  return 0;
}
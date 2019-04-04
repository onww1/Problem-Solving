#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int print(int num, int max) {
  if (num == 1) {
    cout << 1 << ' ';
    return 1;
  }

  if (max == 1) {
    cout << num << ' ';
    return 1;
  }

  int cnt = print(num/2, max-1);
  if (max > cnt) cnt += print(num/2, max - cnt);
  return cnt;
}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  ll n, k;
  cin >> n >> k;
  if (k > n) {
    cout << "NO" << '\n';
    return 0;
  }

  vector<ll> stack;
  ll idx = 0LL;
  while (n / (1LL << idx)) ++idx;
  --idx;

  while (n) {
    if (n >= (1LL << idx)) {
      stack.push_back(1LL << idx);
      n -= (1LL << idx);
    } else {
      --idx;
    }
  }

  if (stack.size() > k) {
    cout << "NO" << '\n';
    return 0;
  } else {
    cout << "YES" << '\n';
    int lack = k - stack.size();
    for (int i=stack.size()-1; i>=0; --i) {
      lack -= (print(stack[i], lack + 1) - 1);
    }
    cout << '\n';
  }

  return 0;
}
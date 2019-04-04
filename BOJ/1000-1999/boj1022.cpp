#include <iostream>
using namespace std;

int get_abs(int a) { return a < 0 ? -a : a; }
int get_max(int a, int b) { return a > b ? a : b; }

int get_val(int r, int c) {
  int val = 1, round = get_max(get_abs(r), get_abs(c));
  if (!round) return val;
  else {
    val = (4 * round * round - 4 * round + 2);
  }

  if (get_abs(c) == round && c > 0) {
    if (r == round) val = (2 * round + 1) * (2 * round + 1);
    else val += (round - r - 1);
  } else if (get_abs(r) == round && r < 0) {
    val += (2 * round - 1);
    val += (round - c);
  } else if (get_abs(c) == round && c < 0) {
    val += (4 * round - 1);
    val += (r + round);
  } else if (get_abs(r) == round && r > 0) {
    val += (6 * round - 1);
    val += (c + round);
  }
  return val;
}

int get_digits(int n) {
  int i = 0, div = 1;
  while (i < 10) {
    if (n / div) ++i;
    else break;

    div *= 10;
  }
  return i;
}

void printInt(int n, int &width) {
  int digits = get_digits(n);
  for (int i = digits; i < width; ++i) cout << ' ';
  cout << n;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int r1, c1, r2, c2, map[50][5];
  cin >> r1 >> c1 >> r2 >> c2;

  int i, j, digits = 0, tmp;
  for (i = r1; i <= r2; ++i) {
    for (j = c1; j <= c2; ++j) {
      map[i - r1][j - c1] = get_val(i, j);
      tmp = get_digits(map[i - r1][j - c1]);
      if (tmp > digits) digits = tmp;
    }
  }

  for (i = r1; i <= r2; ++i) {
    printInt(map[i - r1][0], digits);
    for (j = c1 + 1; j <= c2; ++j) {
      cout << ' ';
      printInt(map[i - r1][j - c1], digits);
    }
    cout << '\n';
  }

  return 0;
}
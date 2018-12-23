#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct point {
  int x, y;
};

bool cmp(point& a, point& b) {
  if (a.x == b.x) return a.y < b.y;
  return a.x < b.x;
}

int get_abs(int a) { return a < 0 ? -a : a;}
int median(int a, int b, int c) {
  if (a <= b && b <= c) return b;
  else if (c <= b && b <= a) return b;
  else if (b <= a && a <= c) return a;
  else if (c <= a && a <= b) return a;
  else if (b <= c && c <= a) return c;
  else return c;
}

int main() {
  int x, y;
  vector<point> v;
  for (int i=0; i<3; ++i) {
    cin >> x >> y;
    v.push_back({x, y});
  }
  sort(v.begin(), v.end(), cmp);
  
  bool isInc = true, isDec = true;
  for (int i=0; i<2; ++i) {
    if (v[i].y > v[i+1].y) isInc = false;
    if (v[i].y < v[i+1].y) isDec = false;
  }

  if (isInc) {
    int min = 1;
    for (int i=0; i<2; ++i) {
      min += v[i+1].y - v[i].y;
      min += v[i+1].x - v[i].x;
    }
    cout << min << '\n';
    x = v[0].x, y = v[0].y;
    for (; x < v[1].x; ++x) cout << x << ' ' << y << '\n';
    for (; y < v[1].y; ++y) cout << x << ' ' << y << '\n';
    for (; x < v[2].x; ++x) cout << x << ' ' << y << '\n';
    for (; y < v[2].y; ++y) cout << x << ' ' << y << '\n';
    cout << x << ' ' << y << '\n';
  } else if (isDec) {
    int min = 1;
    for (int i=0; i<2; ++i) {
      min += v[i].y - v[i+1].y;
      min += v[i+1].x - v[i].x;
    }
    cout << min << '\n';
    x = v[0].x, y = v[0].y;
    for (; x < v[1].x; ++x) cout << x << ' ' << y << '\n';
    for (; y > v[1].y; --y) cout << x << ' ' << y << '\n';
    for (; x < v[2].x; ++x) cout << x << ' ' << y << '\n';
    for (; y > v[2].y; --y) cout << x << ' ' << y << '\n';
    cout << x << ' ' << y << '\n';
  } else {
    int mid_x = v[1].x;
    int mid_y = median(v[0].y, v[1].y, v[2].y);
    int min = 1;
    for (int i=0; i<3; ++i) {
      min += get_abs(mid_x - v[i].x);
      min += get_abs(mid_y - v[i].y);
    }
    cout << min << '\n'; 
    for (int i=0; i<3; ++i) {
      x = v[i].x, y = v[i].y;
      if (x < mid_x) for (; x < mid_x; ++x) cout << x << ' ' << y << '\n';
      else for (; x > mid_x; --x) cout << x << ' ' << y << '\n';
      if (y < mid_y) for (; y < mid_y; ++y) cout << x << ' ' << y << '\n';
      else for (; y > mid_y; --y) cout << x << ' ' << y << '\n';
    }
    cout << mid_x << ' ' << mid_y << '\n';
  }

  return 0;
}
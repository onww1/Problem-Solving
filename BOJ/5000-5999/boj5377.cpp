#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef long double ldb;
typedef pair<ll,ll> pll;
typedef pair<ldb, int> pdi;

struct line {
  pll p1, p2;
};

const int MAX = 1000;
ll T, N, X, Y, P, P_SZ;
pll points[MAX + 2], SRC, DST;
pll BASE, INF = { 100000, 1 };
vector <pdi> edges[MAX + 2];
ldb dist[MAX + 2];
bool visited[MAX + 2];

ll CCW(pll p1, pll p2, pll p3);
ldb distance(pll p1, pll p2);
ldb calculate(int idx1, int idx2);
bool cmp_angle(pll a, pll b);
bool isInner(pll point, vector <line> &polygon);
vector <int> make_convex_hull(pll points[], ll size);
void find_outer(pll &point, vector <int> &outer, vector <int> &convex);

int main(int argc, char *argv[]) {

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  for (scanf("%lld", &T); T--;) {
    scanf("%lld %lld %lld %lld %lld", &SRC.X, &SRC.Y, &DST.X, &DST.Y, &N);
    for (int i = 0; i < N; ++i) {
      scanf("%lld %lld", &X, &Y);
      points[i] = { X, Y };
    }

    vector <int> convex = make_convex_hull(points, N);
    vector <line> polygon;

    puts("Points");
    for (int i = 0; i < convex.size(); ++i) {
      printf("Point #%d : (%lld, %lld)\n", i, points[convex[i]].X, points[convex[i]].Y);
    }

    for (int i = 0; i < convex.size(); ++i) 
      polygon.push_back(line({ points[convex[i]], points[convex[(i + 1) % convex.size()]]}));

    bool valid = true;
    if (convex.size() > 2 && isInner(SRC, polygon)) valid = false;
    if (convex.size() > 2 && isInner(DST, polygon)) valid = false;

    if (!valid) {
      puts("IMPOSSIBLE");
      continue;
    }

    bool inRange = false, direct_valid = true;
    int idx = 1, prev = CCW(SRC, points[convex[0]], DST);
    for (; idx < convex.size(); ++idx) {
      int cur = CCW(SRC, points[convex[idx]], DST);
      if (cur == 0) {
        cur = CCW(SRC, points[convex[++idx]], DST);
        if (cur != prev) {
          inRange = true;
          break;
        }
      }
      if (prev * cur < 0) {
        inRange = true;
        break;
      }
    }

    ldb direct = distance(SRC, DST);
    vector <int> outer_SRC, outer_DST;
    find_outer(SRC, outer_SRC, convex);
    find_outer(DST, outer_DST, convex);

    puts("SRC");
    printf("%d, %d\n", outer_SRC[0], outer_SRC[1]);
    puts("DST");
    printf("%d, %d\n", outer_DST[0], outer_DST[1]);


    if (inRange) {
      pll mid = { (points[outer_SRC[0]].X + points[outer_SRC[1]].X) / 2, (points[outer_SRC[0]].Y + points[outer_SRC[1]].Y) / 2 };
      if (distance(SRC, mid) < direct) direct_valid = false;
    }

    if (direct_valid) {
      printf("%.3Lf\n", direct);
      continue;
    }

    ldb v[4];
    for (int i = 0, idx = 0; i < 2; ++i) for (int j = 0; j < 2; ++j)
      v[idx++] = calculate(outer_SRC[i], outer_DST[j]);

    printf("%.3Lf\n", min({v[0], v[1], v[2], v[3]}));
  }  

  return 0;
}

ll CCW(pll p1, pll p2, pll p3) {
  ll ret = 0;
  ret += p1.X * (p2.Y - p3.Y);
  ret += p2.X * (p3.Y - p1.Y);
  ret += p3.X * (p1.Y - p2.Y);
  return ret > 0 ? 1 : ret < 0 ? -1 : 0;
}

ldb distance(pll p1, pll p2) {
  ll dx = p2.X - p1.X;
  ll dy = p2.Y - p1.Y;
  return (ldb)sqrt(dx * dx + dy * dy);
}

ldb calculate(int idx1, int idx2) {
  ldb ret1, ret2;
  ret1 = ret2 = distance(SRC, points[idx1]) + distance(DST, points[idx2]);
  for (int i = idx1; i != idx2; ++i) {

  }
  for (int i = idx1; i != idx2; --i) {
    
  }
}

bool cmp_angle(pll a, pll b) {
  ll ccw = CCW(BASE, a, b);
  if (ccw == 0) return a.X < b.X;
  return ccw > 0;
}

bool isInner(pll point, vector <line> &polygon) {
  line cur = { point, INF };
  int cnt = 0;
  for (line L : polygon) {
    ll ccw1 = CCW(cur.p1, cur.p2, L.p1) * CCW(cur.p1, cur.p2, L.p2);
    ll ccw2 = CCW(L.p1, L.p2, cur.p1) * CCW(L.p1, L.p2, cur.p2);
    if (ccw1 < 0 && ccw2 < 0) cnt++;
    if (ccw1 < 0 && ccw2 == 0) return false;
  }

  return cnt % 2 == 1;
}

vector <int> make_convex_hull(pll points[], ll size) {
  sort(points, points + size);
  BASE = points[0];
  sort(points + 1, points + size, cmp_angle);

  vector <int> convex;
  convex.push_back(0);
  if (size == 1) return convex;

  convex.push_back(1);
  if (size == 2) return convex;

  int convex_size = 2;
  for (int i = 2; i < size; ++i) {
    while (convex_size > 1 && CCW(points[convex[convex_size - 2]], points[convex[convex_size - 1]], points[i]) <= 0) {
      convex.pop_back();
      convex_size--;
    }
    convex.push_back(i);
    convex_size++;
  }

  return convex;
}

void find_outer(pll &point, vector <int> &outer, vector <int> &convex) {
  if (convex.size() == 1) outer.push_back(convex[0]), outer.push_back(convex[0]);
  else if (convex.size() == 2) outer.push_back(convex[0]), outer.push_back(convex[1]);
  else {
    int prev = CCW(point, points[convex[convex.size() - 1]], points[convex[0]]);
    for (int i = 0; i < convex.size(); ++i) {
      int cur = CCW(point, points[convex[i]], points[convex[(i + 1) % convex.size()]]);
      if (cur * prev <= 0) outer.push_back(i);
      prev = cur;
    }
  }
}
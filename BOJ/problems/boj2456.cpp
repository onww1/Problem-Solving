#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct person {
  int p[3], i, s;
  person(int n) {
    p[0] = 0, p[1] = 0, p[2] = 0;
    i = n, s = 0;
  }
};

bool cmp(person a, person b) {
  if (a.s == b.s && a.p[2] == b.p[2] && a.p[1] == b.p[1]) return a.p[0] > b.p[0];
  else if (a.s == b.s && a.p[2] == b.p[2]) return a.p[1] > b.p[1];
  else if (a.s == b.s) return a.p[2] > b.p[2];
  return a.s > b.s;
}

int main(int argc, char *argv[]) {
  int n, i, cnt[4][3] = {0}, a, b, c;
  vector <person> vec;
  for (i = 1; i <= 3; ++i) vec.push_back(person(i));

  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d %d %d", &a, &b, &c);
    vec[0].p[a-1] += 1; vec[0].s += a;
    vec[1].p[b-1] += 1; vec[1].s += b;
    vec[2].p[c-1] += 1; vec[2].s += c;
  }
  sort(vec.begin(), vec.end(), cmp);
  if (vec[0].s > vec[1].s) return !printf("%d %d\n", vec[0].i, vec[0].s);
  if (vec[0].p[2] > vec[1].p[2]) return !printf("%d %d\n", vec[0].i, vec[0].s);
  if (vec[0].p[1] > vec[1].p[1]) return !printf("%d %d\n", vec[0].i, vec[0].s);
  return !printf("0 %d\n", vec[0].s);
}
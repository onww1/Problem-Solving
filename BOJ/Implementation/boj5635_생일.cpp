#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct person {
  char name[20];
  int y, m, d;
};

bool cmp(person a, person b) {
  if (a.y == b.y && a.m == b.m) return a.d < b.d;
  else if (a.y == b.y) return a.m < b.m;
  return a.y < b.y; 
}

int main(int argc, char *argv[]) {
  int n, i;
  vector <person> vec;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    person p;
    scanf(" %s %d %d %d", p.name, &p.d, &p.m, &p.y);
    vec.push_back(p);
  }
  sort(vec.begin(), vec.end(), cmp);
  return !printf("%s\n%s\n", vec[n-1].name, vec[0].name);
}

#include <cstdio>
#include <vector>
#include <map>
using namespace std;

map <int, int> m;
map <int, int>::iterator it;
vector <int> s;

int pow(int base, int exp) {
  int ret = 1;
  while (exp > 0) {
    if (exp % 2) ret *= base;
    base *= base;
    exp /= 2;
  }
  return ret;
}

int cal(int n, int p) {
  int ret = 0;
  while (n) {
    ret += pow(n%10, p);
    n /= 10;
  }
  return ret;
}

int main(int argc, char *argv[]) {
  int a, p, cnt = 1;
  scanf("%d %d", &a, &p);
  s.push_back(a);
  m.insert({a, 0});
  while (1) {
    a = cal(a, p);
    it = m.find(a);
    if (it != m.end()) {
      return !printf("%d\n", it->second);
    } else {
      m.insert({a, cnt++});
    }
  }
  return 0;
}
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]) {
  priority_queue < int, vector<int>, greater<int> > pq;
  int n, a, sum = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a), pq.push(a);
  while (pq.size() > 1) {
    int x = pq.top(); pq.pop();
    int y = pq.top(); pq.pop();
    sum += (x + y);
    pq.push(x + y);
  } 
  return !printf("%d\n", sum);
}
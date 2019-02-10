#include <cstdio>
#include <queue>
#include <algorithm>
#define X first;
#define Y second;
using namespace std;
typedef pair<int,int> pii;

const int MAX = 1e5;
int N, T, P, K[MAX + 5];
priority_queue < int > gpq;
priority_queue < int, vector<int>, greater<int> > lpq;

int main(int argc, char *argv[]) {
  scanf("%d %d %d", &N, &T, &P);
  for (int i = 0; i < N; ++i) scanf("%d", K + i);
  int mx = 0, cur = 0;
  for (long long i = 0; i < N; ++i) {
    lpq.push(K[i]);
    while (!lpq.empty() && (gpq.empty() || gpq.top() > lpq.top())) {
      cur += lpq.top();
      gpq.push(lpq.top());
      lpq.pop();
    }
    while (!gpq.empty() && cur > T - i * P) {
      cur -= gpq.top();
      lpq.push(gpq.top());
      gpq.pop();
    }
    while (!lpq.empty() && cur + lpq.top() <= T - i * P) {
      cur += lpq.top();
      gpq.push(lpq.top());
      lpq.pop();
    }
    mx = max(mx, (int)gpq.size());
  }
  return !printf("%d\n", mx);
}
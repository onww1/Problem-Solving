#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

char buf[1 << 17];
inline char read() {
  static int idx = 1 << 17;
  if (idx == 1 << 17) {
    int nidx = fread(buf, 1, 1 << 17, stdin);
    if (!nidx) return 0;
    idx = 0;
  }
  return buf[idx++];
}
inline int readInt() {
  int sum = 0;
  char now = read();
  while (now == ' ' || now == '\n') now = read();
  while ('0' <= now && now <= '9') sum = sum * 10 + now - '0', now = read();
  return sum;
}

int a[100050];
bool visited[100050];

int solve(int node) {
  vector <int> path;
  path.push_back(node); 
  visited[node] = true;
  int ret = 0;

  while (1) {
    node = path.back();
    if (!visited[a[node]]) {
      path.push_back(a[node]); 
      visited[a[node]] = true;
    } else {
      ret = path.size();
      for (int i = 0; i < path.size(); ++i) {
        if (path[i] != a[node]) --ret;
        else break;
      }
      break;
    }
  }
  return ret;
}

int main(int argc, char *argv[]) {
  int t, n, s, i;
  t = readInt();
  while (t--) {
    s = n = readInt();
    for (i = 1; i <= n; ++i) a[i] = readInt();
    memset(visited, false, n+1);
    for (i = 1; i <= n; ++i) 
      if (!visited[i]) s -= solve(i);
    printf("%d\n", s);
  }
  return 0;
}
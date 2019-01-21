#include <cstdio>
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

vector <int> edges[505];
bool visited[505];
int main(int argc, char *argv[]) {
  int n, m, u, v, i;
  n = readInt();
  m = readInt();
  for (i = 0; i < m; ++i) {
    u = readInt();
    v = readInt();
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  int s = 0;
  visited[1] = true;
  vector <int> friends;
  for (auto it : edges[1]) {
    visited[it] = true;
    friends.push_back(it);   
    ++s;
  }
  for (i = 0; i < friends.size(); ++i) {
    for (auto it : edges[friends[i]]) {
      if (visited[it]) continue;
      visited[it] = true;
      ++s;
    }
  }
  return !printf("%d\n", s);
}
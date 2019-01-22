#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> ver, hor;
int main(int argc, char *argv[]) {
  int w, h, n, d, p, i;
  scanf("%d %d %d", &w, &h, &n);
  for (i = 0; i < n; ++i) {
    scanf("%d %d", &d, &p);
    if (d) ver.push_back(p);
    else hor.push_back(p);
  }
  sort(ver.begin(), ver.end());
  sort(hor.begin(), hor.end());
  int hmx = hor.empty() ? h : hor[0];
  int wmx = ver.empty() ? w : ver[0];
  for (i = 0; i < ver.size(); ++i) {
    if (i == ver.size() - 1) wmx = max(wmx, w - ver[i]);
    else wmx = max(wmx, ver[i+1] - ver[i]);
  }
  for (i = 0; i < hor.size(); ++i) {
    if (i == hor.size() - 1) hmx = max(hmx, h - hor[i]);
    else hmx = max(hmx, hor[i+1] - hor[i]);
  }
  return !printf("%d\n", hmx * wmx);
}
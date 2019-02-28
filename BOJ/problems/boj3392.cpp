/*
 *  BOJ 3392. 화성 지도 
 * 
 *  시간 복잡도 : O(NlogK)  (K : 30000) 
 *  공간 복잡도 : O(2^logN)
 * 
 *  주어지는 좌표들에 대해서 직사각형의 왼쪽 변과 오른쪽 변을 나누어서 따로 저장하고, 
 *  이게 시작하는 변인지 끝나는 변인지를 함께 저장해둔 다음, x좌표로 정렬합니다. 
 *  그런 다음 순서대로 가면서 같은 x좌표에서 y축에 대한 세그먼트 트리에 그 값들을 반영하고, 
 *  현재 채워져 있는 칸의 수를 세어서 면적에 더해줍니다. 
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#define X first
#define Y second
using namespace std;

// Fast I/O
const int BUFFER_SIZE = 1 << 17;
char buf[BUFFER_SIZE];
inline char read() {
  static int idx = BUFFER_SIZE;
  if (idx == BUFFER_SIZE) {
    int nidx = fread(buf, 1, BUFFER_SIZE, stdin);
    if (!nidx) return 0;
    idx = 0;
  }
  return buf[idx++];
}
inline int readInt() {
  int sum = 0, flg = 1;
  char now = read();
  while (now == ' ' || now == '\n') now = read();
  if (now == '-') flg = 0, now = read();
  while ('0' <= now && now <= '9') sum = sum * 10 + now - '0', now = read();
  return flg ? sum : -sum;
}

struct line {
  int x, y1, y2, d;
};

bool cmp(line &a, line &b) {
  return a.x < b.x; 
}

const int SZ = 1 << 15;
const int MAX = 3e4;
int N, tree[2 * SZ], lazy[2 * SZ];
vector <line> lines;

void update_range(int node, int start, int end, int left, int right, int diff);

int main(int argc, char *argv[]) {
  N = readInt();
  int x, y, xx, yy;
  for (int i = 0; i < N; ++i) {
     x = readInt(),  y = readInt();
    xx = readInt(), yy = readInt();

    // 시작하는 변이면 1을 더해줘야 하므로 d값을 1로 하고, 
    // 끝나는 변이면 1을 빼줘야 하므로 d값을 -1로 합니다.
    lines.push_back({x, y, yy - 1, 1});
    lines.push_back({xx, y, yy - 1, -1});
  }

  // x좌표에 대하여 정렬
  sort(lines.begin(), lines.end(), cmp);

  int pos = lines[0].x, idx = 0, ans = 0;
  while (idx < 2 * N) {
    // 같은 x좌표들은 모두 처리
    while (idx < 2 * N && lines[idx].x == pos) {
      update_range(1, 0, MAX, lines[idx].y1, lines[idx].y2, lines[idx].d);
      idx++;
    }

    // 인접한 x좌표의 차이만큼은 직사각형이 있으므로 곱해서 더한다.
    ans += (lines[idx].x - pos) * tree[1];

    // 다음 x좌표로 이동
    pos = lines[idx].x;
  }

  return !printf("%d\n", ans);
}

// 쿼리에 대하여 그 쿼리에 해당하는 범위에 완전히 들어가면 그 부분에 대한 노드에 1을 더하거나 1을 빼고, 
// 그러한 값이 0이 아니라면 그 구간이 현재 채워져 있다는 의미이므로 그 구간의 길이를 tree에 넣어줍니다.
// 그리고 0이라면 더 하위로 내려가서 값을 가져오고, 리프라면 0을 넣어줍니다.
void update_range(int node, int start, int end, int left, int right, int diff) {
  if (end < left || right < start) return;

  // lazy 배열 갱신
  if (left <= start && end <= right) {
    lazy[node] += diff;
  } else {
    int mid = (start + end) / 2;
    update_range(node * 2, start, mid, left, right, diff);
    update_range(node * 2 + 1, mid + 1, end, left, right, diff);
  }

  // tree 배열 갱신
  if (lazy[node]) tree[node] = end - start + 1;
  else if (start != end) tree[node] = tree[node * 2] + tree[node * 2 + 1];
  else tree[node] = 0;
}

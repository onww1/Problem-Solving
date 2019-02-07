/*
 *  BOJ 3090. 차이를 최소로 
 * 
 *  인접한 수의 최댓값의 최솟값을 이분탐색으로 결정합니다. 
 *  그 수가 되는지 확인하는 과정이 어려웠는데, 저는 일단 기존 배열을 복사한 다음,
 *  우선순위 큐에 넣어서 가장 작은 수부터 시작해서 주변과의 차이를 정해둔 수보다 작거나 같도록 
 *  계속 바꿔갔습니다. 그렇게 바꾼 횟수가 가능한 수보다 크면 실패고, 아니라면 성공입니다.
 */

#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
const int MAX = 1e5;
int a[MAX + 1], ans[MAX + 1], n, t;
pii p[MAX + 1];

// 정해둔 값의 차이로 수열을 바꿀 수 있는지 확인.
bool solve(int diff) {
  priority_queue < pii, vector<pii>, greater<pii> > pq;
  int arr[MAX + 1], tmp = t, idx;
  
  // 우선순위 큐에 모든 값을 넣음.
  for (int i = 0; i < n; ++i) arr[i] = a[i], pq.push({a[i], i});

  // 우선순위 큐에서 가장 작은 수부터 뽑아내면서 인접한 수의 차이를 정해둔 값보다 크지 않도록 바꿈.
  while (!pq.empty()) {
    idx = pq.top().second; pq.pop();
    if (idx > 0 && arr[idx-1] > arr[idx] + diff) {
      tmp -= (arr[idx - 1] - arr[idx] - diff);
      arr[idx - 1] = arr[idx] + diff;
      pq.push({arr[idx - 1], idx - 1});
    }
    if (idx < n - 1 && arr[idx+1] > arr[idx] + diff) {
      tmp -= (arr[idx + 1] - arr[idx] - diff);
      arr[idx + 1] = arr[idx] + diff;
      pq.push({arr[idx + 1], idx + 1});
    }
  }

  // 값을 바꾼 횟수가 정해진 값보다 크면 실패, 아니라면 성공
  if (tmp < 0) return false;
  for (int i = 0; i < n; ++i) ans[i] = arr[i];
  return true;
}

int main(int argc, char *argv[]) {
  int s = 0, e = 0, m;
  scanf("%d %d %d", &n, &t, a);
  
  for (int i = 1; i < n; ++i) {
    scanf("%d", a + i);
    e = max(e, abs(a[i] - a[i-1]) + 1);
  }

  // 이분탐색
  while (s < e) {
    m = (s + e) / 2;
    if (solve(m)) e = m;  // 성공시 최솟값을 줄이고,
    else s = m + 1;       // 실패시 최솟값을 늘린다.
  }
  for (int i = 0; i < n; ++i) printf("%d ", ans[i]);
  return !printf("\n");
}
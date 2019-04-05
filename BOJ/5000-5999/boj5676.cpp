/*
 *  BOJ 5676. 음주 코딩 
 * 
 *  시간 복잡도 : O((N + M) * logN)
 *  공간 복잡도 : O(N)
 * 
 *  곱셈에서 양수는 큰 의미가 없기 때문에 구간에 대해서 0의 수를 세어주는 펜윅트리와 
 *  음수의 수를 세어주는 펜윅트리를 관리해서 주어진 구간에 대해 0이 있으면 0을 출력하고, 
 *  0이 없는 상태에서 음수가 홀수개 있으면 -를 출력하고, 아니라면 +를 출력하도록 했습니다.
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1e5;
int N, K, idx, A[MAX + 1], m[MAX + 1], z[MAX + 1];
char ans[MAX + 1];

void update(int *arr, int node, int diff);
int sum(int *arr, int node);

int main(int argc, char *argv[]) {
  while (~scanf("%d %d", &N, &K)) {
    // 초기화
    memset(m, 0, sizeof(m));
    memset(z, 0, sizeof(z));
    idx = 0;

    // 입력
    for (int i = 1; i <= N; ++i) {
      scanf("%d", A + i);
      if (!A[i]) update(z, i, 1);
      else if (A[i] < 0) update(m, i, 1);
    }

    char c; int a, b;
    while (K--) {
      scanf(" %c %d %d", &c, &a, &b);
      if (c == 'C') {
        // 이전에 있었던 값에 대해서 빼줌.
        if (!A[a]) update(z, a, -1);
        else if (A[a] < 0) update(m, a, -1);

        A[a] = b;

        // 새로운 값에 대해서 더해줌.
        if (!A[a]) update(z, a, 1);
        else if (A[a] < 0) update(m, a, 1);
      } else {
        // 0이 있으면 0, 0이 없고 음수가 홀수개면 -, 나머지 상황은 +
        if (sum(z, b) - sum(z, a - 1) > 0) ans[idx++] = '0';
        else if ((sum(m, b) - sum(m, a - 1)) % 2) ans[idx++] = '-';
        else ans[idx++] = '+';
      }
    }
    ans[idx] = 0;
    printf("%s\n", ans);
  }

  return 0;
}

// 펜윅트리 업데이트 함수
void update(int *arr, int node, int diff) {
  while (node <= N) {
    arr[node] += diff;
    node += node & -node;
  }
}

// 펜윅트리 1 ~ node 구간의 합 함수
int sum(int *arr, int node) {
  int ret = 0;
  while (node) {
    ret += arr[node];
    node -= node & -node;
  }
  return ret;
}
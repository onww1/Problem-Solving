/*
 *  BOJ 4386. 별자리 만들기
 *  
 *  시간 복잡도 : O(N^2)
 *  공간 복잡도 : O(N^2)
 *
 *  들어오는 인풋에 대해서 모든 간선을 만들어주고, 그것을 우선순위 큐에 넣어줍니다.
 *  그리고 그것에 대해서 크루스칼 알고리즘을 사용하여 MST를 만들어주면 됩니다.
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#define X first
#define Y second
using namespace std;

typedef long double ldb;
typedef pair <int, int> pii;
typedef pair<ldb, ldb> pdd;
typedef pair<ldb, pii> pdii;

const int MAX = 100;
int N, C, pa[MAX + 1];
pdd P[MAX + 1];

// 유니온 파인드 함수
int _find(int a) {
    if (pa[a] < 0) return a;
    return pa[a] = _find(pa[a]);
}

void _union(int a, int b) {
    int a_root = _find(a);
    int b_root = _find(b);
    if (a_root != b_root) 
        pa[a_root] = b_root;
}

int main(int argc, char *argv[]) {
    memset(pa, -1, sizeof(pa));
    priority_queue <pdii, vector<pdii>, greater<pdii>> pq;

    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        // 현재 인풋을 저장.
        scanf("%Lf %Lf", &P[i].X, &P[i].Y);
        for (int j = 0; j < i; ++j) {
            // 이전 인풋들에 대해서 거리를 모두 구하고, 우선순위 큐에 간선으로 넣어줌.
            ldb dist = (ldb)sqrt((P[i].X - P[j].X) * (P[i].X - P[j].X) + (P[i].Y - P[j].Y) * (P[i].Y - P[j].Y));
            pq.push({dist, {i, j}});
       }
    }
  
    // 크루스칼 알고리즘으로 MST를 만듦.
    ldb ans = 0;
    while (!pq.empty()) {
        ldb dist = pq.top().X;
        int u = pq.top().Y.X;
        int v = pq.top().Y.Y;
        pq.pop();
        
        if (_find(u) == _find(v)) continue;
        _union(u, v);
        ans += dist;
        if (++C == N - 1) break;
    }

    // 결과 출력
    printf("%.12Lf\n", ans);
    return 0;
}
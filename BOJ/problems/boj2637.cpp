/*
 *  BOJ 2637. 장난감 조립
 *
 *  시간 복잡도 : O(N + M)
 *  공간 복잡도 : O(N^2)
 *
 *  입력에 대해서 자신을 필요로 하는 부품을 자신의 벡터에 넣었습니다.
 *  그리고 indegree도 카운트 한다음 indegree가 0인 부품들을 모두 기본 부품으로써 1로 초기화하고, 
 *  위상정렬을 하면서 자신을 필요로 하는 노드들에 기본부품의 수를 카운트해줬습니다.
 *  그렇게 완제품까지 가면 완제품에는 완제품을 만들 때 필요로 하는 모든 기본 부품의 수가 저장되어 있습니다.
 *
 *  이 때, A[i][j]는 i를 만들 때 필요로 하는 j번 부품의 수입니다.
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;

const int MAX = 100;
int N, M, indegree[MAX + 1], A[MAX + 1][MAX + 1];
vector <pii> edges[MAX + 1];

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &M);
    for (int i = 0, X, Y, K; i < M; ++i) {
        scanf("%d %d %d", &X, &Y, &K);
        edges[Y].push_back({X, K});     // 자신을 필요로 하는 부품을 추가
        indegree[X]++;                  // 자신을 필요로 하는 부품에 indegree 증가
    }

    queue <int> Q;
    for (int i = 1; i <= N; ++i) {
        if (!indegree[i]) {             // 리프 (기본 부품)을 모두 1로 초기화하고 큐에 넣는다.
            A[i][i] = 1;
            Q.push(i);
        }
    }

    // 위상정렬
    while (!Q.empty()) {   
        int current = Q.front();
        Q.pop();

        for (pii next : edges[current]) {
            for (int i = 1; i <= N; ++i)    // 모든 부품에 대해서 필요한 만큼 넘겨준다.
                A[next.X][i] += A[current][i] * next.Y;
            indegree[next.X]--;
            if (!indegree[next.X]) Q.push(next.X);  // 더 이상 가르키는게 없으면 큐에 넣는다.
        }
    }

    // 결과 출력
    for (int i = 1; i <= N; ++i) 
        if (A[N][i]) printf("%d %d\n", i, A[N][i]); 

    return 0;
}

/*
// 왜 안되는지 모르겠는 코드입니다.

const int MAX = 100;
int N, M, indegree[MAX + 1], A[MAX + 1];
bool isNotBasic[MAX + 1];
vector <pii> edges[MAX + 1];

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &M);
    for (int i = 0, X, Y, K; i < M; ++i) {
        scanf("%d %d %d", &X, &Y, &K);
        isNotBasic[X] = true;       // 기본 부품이 아니라는 것을 체크
        edges[X].push_back({Y, K}); // 자신에게 필요한 부품을 가르킴
        indegree[Y]++;              // 자신에게 들어오는 간선의 수를 카운트
    }

    queue <int> Q;
    Q.push(N); A[N] = 1;            // 완제품은 1개만 필요하므로 1로 지정.

    // 위상정렬
    while (!Q.empty()) {
        int current = Q.front();
        Q.pop();

        for (pii next : edges[current]) {
            // 자신이 필요한 갯수에 자신을 만들 때 필요한 다음 부품의 수를 곱해서 다음 부품에 더해줌.
            A[next.X] += A[current] * next.Y;
            indegree[next.X]--;
            if (!indegree[next.X]) Q.push(next.X);
        }

        for (int i = 1; i <= N; ++i) printf("%d ", A[i]);
        puts("");
    }

    for (int i = 1; i <= N; ++i) 
        if (!isNotBasic[i] && A[i]) printf("%d %d\n", i, A[i]);

    return 0;
}
*/
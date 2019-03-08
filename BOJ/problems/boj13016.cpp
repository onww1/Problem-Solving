/*
 *  BOJ 13016. 내 왼손에는 흑염룡이 잠들어 있다.
 *
 *  시간 복잡도 : O(N)
 *  공간 복잡도 : O(N)
 *
 *  예전에 트리 문제 풀던 것과 비슷하게 모든 노드에서 한 번씩 확인하면 시간초과가 나니까 
 *  트리를 한 번 순회할 때 모든 노드를 처리할 수 있도록 처리를 해야 하는 문제였습니다.
 *  
 *  저는 DFS 함수가 2개 있는데, 첫 번째는 노드 1에서 시작해서 자식 노드별로 가장 먼 거리와 그 다음으로
 *  먼 거리를 저장해둡니다. 이때, 가장 먼거리에 해당하는 노드의 인덱스도 저장을 해둡니다.
 *  그 다음 두 번째 DFS에서는 자식 노드에 대해서 호출을 할 떄, 현재 가려고 하는 자식 노드 외의 다른 노드까지의
 *  거리중 가장 큰 값과 가려고 하는 자식 노드와의 간선 거리를 더한 값을 넘겨주는 것입니다. 
 *  그렇게 자식 노드는 그 값을 받고, 현재 자신이 갖고 있는 다른 MAX값들과 비교하여 갱신을 해주고, 
 *  그 중에서 가장 큰 값을 자신의 값으로 취하고 반복하여 자식 노드에 대해서 똑같은 작업을 해줍니다. 
 *  이렇게 D 배열을 채우고 다 출력을 하면 끝납니다.
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

const int MAX = 50000;
int N, D[MAX + 1], MX[MAX + 1][3];
vector <pii> edges[MAX + 1];

// 각 자식 노드 별로 최대 거리가 얼마나 되는지 리턴받고, 그 중에서 가장 큰 값과 다음으로 큰 값을 저장.
int DFS1(int node, int parent) {
    for (pii next : edges[node]) {
        if (next.X != parent) {
            int val = DFS1(next.X, node) + next.Y;
            if (MX[node][0] < val) {
                MX[node][1] = MX[node][0];
                MX[node][0] = val;
                MX[node][2] = next.X;
            } else MX[node][1] = max(MX[node][1], val);
        }
    }
    return MX[node][0];
}

// 자식 노드에게 그 자식노드 방향외의 다른 방향에서의 최댓값과 그 노드로 가는 간선의 가중치를 더한 값을 넘겨줍니다.
// 이때, 그 받은 값으로 MX의 값을 갱신하고, 이 중 가장 큰 값을 자신의 값으로 취합니다. 
// 그 다음, 자식에게 똑같은 작업을 반복하는 식으로 해서 D배열을 채우는 함수입니다.
void DFS2(int node, int parent, int val) {
    if (val > MX[node][0]) {
        MX[node][1] = MX[node][1];
        MX[node][0] = val;
        MX[node][2] = parent;
    } else MX[node][1] = max(MX[node][1], val);

    D[node] = MX[node][0];
    for (pii next : edges[node]) {
        if (next.X != parent) {
            if (next.X != MX[node][2]) DFS2(next.X, node, MX[node][0] + next.Y);
            else DFS2(next.X, node, MX[node][1] + next.Y);    
        }
    }
}

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 1, u, v, w; i < N; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }

    DFS1(1, 0);
    DFS2(1, 0, 0);

    for (int i = 1; i <= N; ++i) printf("%d\n", D[i]);
    return 0;
}
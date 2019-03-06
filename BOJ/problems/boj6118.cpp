/*
 *  BOJ 6118. 숨바꼭질
 * 
 *  시간 복잡도 : O(V + E)
 *  공간 복잡도 : O(E)
 *  
 *  단순 BFS 문제입니다.
 *  BFS를 하면서 depth가 깊어질 때마다 최대 길이, 같은 길이 갯수, 그 중 작은 인덱스를 갱신합니다.
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 20000;
int N, M, visited[MAX + 1];
vector <int> edges[MAX + 1];

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &M);
    for (int i = 0, U, V; i < M; ++i) {
        scanf("%d %d", &U, &V);
        edges[U].push_back(V);
        edges[V].push_back(U);
    }

    queue <int> Q;
    Q.push(1); visited[1] = true;

    int T = 0, size, mx_idx = 0, mx = 0, mx_cnt = 0;
    while (!Q.empty()) {
        // Q에 데이터가 있다는 것은 더 깊은 깊이로 간다는 것이므로 새로 갱신
        size = Q.size();
        if (size) {
            mx_cnt = size;
            mx = T;
            mx_idx = INF;
        }

        for (int i = 0; i < size; ++i) {
            int current = Q.front();
            Q.pop();
            
            // 같은 길이 중에서 가장 작은 인덱스를 찾자.
            mx_idx = min(mx_idx, current);

            for (int next : edges[current]) {
                if (!visited[next]) {
                    visited[next] = true;
                    Q.push(next);
                }
            }
        }
        ++T;
    }

    printf("%d %d %d\n", mx_idx, mx, mx_cnt);
    return 0;
}
/*
 *  BOJ 17071. 숨바꼭질 5
 *
 *  시간 복잡도 : O(K)   (K = 500,000)
 *  공갼 복잡도 : O(K)   (K = 500,000)
 *
 *  수빈이가 가는 위치를 홀짝으로 나누어서 visited를 체크하고, 동생이 방문했을 때 홀짝이 같은 상태에서
 *  수빈이가 이미 방문했었더라면 수빈이가 -1, +1을 반복하면서 기다렸으면 되기 때문에 잡았다고 처리할 수 있습니다.
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 5e5;
int N, K, S, T;
bool visited[2][MAX + 1];

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &K);
    visited[0][N] = true;
    queue <int> Q; Q.push(N);

    while (!Q.empty() && K <= MAX) {
        if (S == 0) {
            if (visited[T % 2][K + T]) 
                return !printf("%d\n", T);
            
            S = Q.size();
            K += T++;
        }

        int pos = Q.front();
        Q.pop();

        if (pos + 1 <= MAX && !visited[T % 2][pos + 1]) {
            visited[T % 2][pos + 1] = true;
            Q.push(pos + 1);
        }
        if (pos - 1 >= 0 && !visited[T % 2][pos - 1]) {
            visited[T % 2][pos - 1] = true;
            Q.push(pos - 1);
        }
        if (pos * 2 <= MAX && !visited[T % 2][pos * 2]) {
            visited[T % 2][pos * 2] = true;
            Q.push(pos * 2);
        }

        S--;
    }

    puts("-1");
    return 0;
}
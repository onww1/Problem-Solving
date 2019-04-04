#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

const int MAX = 1e5;
int N, K;
bool visited[MAX + 1];

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &K);
    queue <int> Q;
    Q.push(N); visited[N] = true;

    int T = -1, size = 0;
    while (!Q.empty()) {
        if (!size) {
            size = Q.size();
            T++;
        }

        int cur = Q.front();
        Q.pop(); size--;

        for (int i = 1; cur * i <= MAX; i *= 2) {
            visited[cur * i] = true;
            if (cur * i == K) return !printf("%d\n", T);
            
            if (cur * i > 0 && cur * i - 1 <= MAX && !visited[cur * i - 1]) {
                visited[cur * i - 1] = true;
                Q.push(cur * i - 1);
            }
            if (cur * i + 1 <= MAX && !visited[cur * i + 1]) {
                visited[cur * i + 1] = true;
                Q.push(cur * i + 1);
            }
            if (cur == 0) break;
        }
    }

    return 0;
}
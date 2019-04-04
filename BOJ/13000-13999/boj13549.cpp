#include <algorithm>
#include <cstdio>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

const int MAX = 1e5;
int N, K;
bool visited[MAX + 1];

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &K);
    priority_queue <pii, vector<pii>, greater<pii>> pq;
    pq.push({0, N}); visited[N] = true;

    while (!pq.empty()) {
        int cur = pq.top().Y;
        int T = pq.top().X;
        pq.pop(); 

        if (cur == K) return !printf("%d\n", T);

        if (cur * 2 <= MAX && !visited[cur * 2]) {
            visited[cur * 2] = true;
            pq.push({T, cur * 2});
        }
        if (cur - 1 >= 0 && !visited[cur - 1]) {
            visited[cur - 1] = true;
            pq.push({T + 1, cur - 1});
        }
        if (cur + 1 <= MAX && !visited[cur + 1]) {
            visited[cur + 1] = true;
            pq.push({T + 1, cur + 1});
        }
    }

    return 0;
}
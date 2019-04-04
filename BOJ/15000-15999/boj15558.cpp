#include <algorithm>
#include <cstdio>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

const int MAX = 1e5;
int N, K;
char A[2][MAX + 1];
bool visited[2][MAX + 1];

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &K);
    for (int i = 0; i < 2; ++i) scanf(" %s", A[i]);

    queue <pii> Q;
    Q.push({0, 0});
    visited[0][0] = true;

    int T = -1, size = 0;
    while (!Q.empty()) {
        if (size == 0) {
            size = Q.size();
            T++;
        }

        int col = Q.front().X;
        int pos = Q.front().Y;
        Q.pop(); size--;

        if (pos < T) continue;

        if (pos - 1 > T && A[col][pos - 1] == '1' && !visited[col][pos - 1]) {
            visited[col][pos - 1] = true;
            Q.push({col, pos - 1});
        }

        if (pos + 1 >= N) return !printf("1\n");
        else if (A[col][pos + 1] == '1' && !visited[col][pos + 1]) {
            visited[col][pos + 1] = true;
            Q.push({col, pos + 1});
        }

        if (pos + K >= N) return !printf("1\n");
        else if (A[1 - col][pos + K] == '1' && !visited[1 - col][pos + K]) {
            visited[1 - col][pos + K] = true;
            Q.push({1 - col, pos + K});
        }
    }

    puts("0");
    return 0;
}
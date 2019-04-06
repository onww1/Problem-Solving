#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

const int MAX = 1e5;
int N, K;
pii V[MAX + 1];

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &K);

    queue <int> Q;
    Q.push(N);
    V[N] = {0, 1};

    while (!Q.empty()) {
        int pos = Q.front();
        int T = V[pos].X;
        Q.pop();

        if (pos == K) break;

        if (pos - 1 >= 0) {
            if (!V[pos - 1].Y || V[pos - 1].X > T + 1) {
                V[pos - 1] = {T + 1, V[pos].Y};
                Q.push(pos - 1);
            } else if (V[pos - 1].X == T + 1) V[pos - 1].Y += V[pos].Y;
        } 
        if (pos + 1 <= MAX) {
            if (!V[pos + 1].Y || V[pos + 1].X > T + 1) {
                V[pos + 1] = {T + 1, V[pos].Y};
                Q.push(pos + 1);
            } else if (V[pos + 1].X == T + 1) V[pos + 1].Y += V[pos].Y;
        }
        if (2 * pos <= MAX) {
            if (!V[2 * pos].Y || V[2 * pos].X > T + 1) {
                V[2 * pos] = {T + 1, V[pos].Y};
                Q.push(2 * pos);
            } else if (V[2 * pos].X == T + 1) V[2 * pos].Y += V[pos].Y;
        }
    }

    printf("%d\n%d\n", V[K].X, V[K].Y);
    return 0;
}
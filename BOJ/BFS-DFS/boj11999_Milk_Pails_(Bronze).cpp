#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

int X, Y, M, ans;
bool V[1001];

int main(int argc, char *argv[]) {
    scanf("%d %d %d", &X, &Y, &M);
    queue <int> Q;
    Q.push(0); V[0] = true;
    while (!Q.empty()) {
        int A = Q.front(); Q.pop();
        ans = max(ans, A);
        if (A + X <= M && !V[A + X]) Q.push(A + X), V[A + X] = true;
        if (A + Y <= M && !V[A + Y]) Q.push(A + Y), V[A + Y] = true;
    }
    printf("%d\n", ans);
    return 0;
}
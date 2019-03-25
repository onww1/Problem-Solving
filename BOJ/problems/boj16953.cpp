#include <algorithm>
#include <cstdio>
#include <queue>
#include <set>
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair <ll, int> pli;

set <ll> visited;
ll A, B;

int main(int argc, char *argv[]) {
    scanf("%lld %lld", &A, &B);

    queue <pli> Q;
    Q.push({A, 0});
    visited.insert(A);

    while (!Q.empty()) {
        ll val = Q.front().X;
        int T = Q.front().Y;
        Q.pop();

        if (val == B) return !printf("%d\n", T + 1);

        if (val * 2 <= B) {
            visited.insert(val * 2);
            Q.push({val * 2, T + 1});
        }
        if (val * 10 + 1 <= B) {
            visited.insert(val * 10 + 1);
            Q.push({val * 10 + 1, T + 1});
        }
    }

    puts("-1");
    return 0;
}
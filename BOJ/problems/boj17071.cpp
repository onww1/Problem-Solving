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
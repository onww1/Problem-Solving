#include <algorithm>
#include <cstdio>
using namespace std;

inline int readInt() {
    int sum = 0;
    char now = getchar_unlocked();
    while (now == ' ' || now == '\n') now = getchar_unlocked();
    while ('0' <= now && now <= '9') sum = sum * 10 + now - '0', now = getchar_unlocked();
    return sum;
}

int main(int argc, char *argv[]) {
    int N, A, mx = 0;  
    N = readInt();
    for (int i = 0; i < N; ++i) {
        A = readInt();
        mx = max(mx, A);
    }
    printf("%d\n", mx);
    return 0;
}
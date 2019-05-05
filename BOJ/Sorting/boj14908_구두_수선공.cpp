#include <algorithm>
#include <cstdio>
using namespace std;

struct node {
    int index, T, S;
    bool operator< (const node& other) const {
        if (T * other.S == S * other.T) return index < other.index;
        return S * other.T > T * other.S;
    }
};

node A[1000];
int N;
int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &A[i].T, &A[i].S);
        A[i].index = i + 1;
    }
    sort(A, A + N);
    for (int i = 0; i < N; ++i) printf("%d ", A[i].index);
    puts("");
    return 0;
}
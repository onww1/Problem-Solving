#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int A, B, D, M, N;
vector <int> v;
int main(int argc, char *argv[]) {
    scanf("%d %d %d", &A, &B, &M);
    for (int i = 0; i < M; ++i) {
        scanf("%d", &N);
        D = D * A + N;
    }

    while (D) {
        v.push_back(D % B);
        D /= B;
    }

    while (!v.empty()) {
        printf("%d ", v.back());
        v.pop_back();
    }

    puts("");
    return 0;
}
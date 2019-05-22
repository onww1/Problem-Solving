#include <cstdio>
#include <vector>
using namespace std;

int N, mx, A;
vector <int> mx_idx;

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &A);
        if (A > mx) {
            mx = A;
            mx_idx.clear();
            mx_idx.push_back(i);
        }
        else if (A == mx)
            mx_idx.push_back(i);
    }

    printf("%c\n", mx_idx[0] - 1 > N - mx_idx.back() ? 'B' : mx_idx[0] - 1 == N - mx_idx.back() ? 'X' : 'R');
    return 0;
}
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int MAX = 1e5;
int N, A[MAX + 1], B;

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 1, in; i <= N; ++i) {
        scanf("%d", &in);
        A[in] = i;
    }
        
    vector <int> lis;
    scanf("%d", &B);
    lis.push_back(A[B]);
    for (int i = 1; i < N; ++i) {
        scanf("%d", &B);
        if (A[B] > lis.back()) lis.push_back(A[B]);
        else *lower_bound(lis.begin(), lis.end(), A[B]) = A[B];
    }

    printf("%lu\n", lis.size());
    return 0;
}
#include <algorithm>
#include <cstdio>
using namespace std;

int N, ans, A[100][3]; 

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) 
        scanf("%d %d %d", A[i], A[i] + 1, A[i] + 2);

    for (int i = 1; i <= 3; ++i) {
        int pos = i, cnt = 0;
        for (int j = 0; j < N; ++j) {
            if (pos == A[j][0]) pos = A[j][1];
            else if (pos == A[j][1]) pos = A[j][0];
            if (pos == A[j][2]) cnt++;
        }
        ans = max(ans, cnt);
    }

    printf("%d\n", ans);
    return 0;
}
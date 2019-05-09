#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX = 1e5;
int N, mx = 1, A[MAX];

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d", A + i);

    for (int i = 1, len = 1; i < N; ++i) {
        if (A[i] > A[i - 1]) len++;
        else if (A[i] == A[i - 1]) {
            int len2 = 0;
            for (; i < N && len2 < len; ++i, ++len2) 
                if (A[i] != A[i - len2 * 2 - 1]) break;
            mx = max(mx, len2 * 2);
            len = 1; 
            while (i < N && A[i] <= A[i - 1]) ++i;
            --i;
        } 
        else {
            int len2 = 0;
            for (; i < N && len2 < len - 1; ++i, ++len2)
                if (A[i] != A[i - len2 * 2 - 2]) break;
            mx = max(mx, len2 * 2 + 1);
            len = 1; 
            while (i < N && A[i] < A[i - 1]) ++i;
            --i;
        }
    }

    printf("%d\n", mx);
    return 0;
}
#include <algorithm>
#include <cstdio>
using namespace std;

int N, W[1000];
int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (i = 0; i < N; ++i) scanf("%d", W + i);
    sort(W, W + N);

    int sum = 1;
    for (int i = 0; i < N; ++i) {
        if (sum < W[i]) break;
        sum += W[i];
    }
 
    printf("%d\n", sum);   
    return 0;
}
#include <cstdio>
int main() {
    int N, K, i, C = 1;  
    scanf("%d %d", &N, &K);
    for (i = 2; i <= N; ++i) {
    	C += K % i;
    	if (C > i) C -= i;
    }
    printf("%d\n", C);
    return 0;
}
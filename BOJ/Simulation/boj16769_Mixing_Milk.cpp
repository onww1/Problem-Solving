#include <cstdio>

int C[3], A[3];
int main(int argc, char *argv[]) {
    for (int i = 0; i < 3; ++i) 
        scanf("%d %d", C + i, A + i);

    for (int i = 0; i < 100; ++i) {
        int cur = i % 3;
        int next = (cur + 1) % 3;
        if (A[cur] + A[next] >= C[next]) {
            A[cur] = A[cur] + A[next] - C[next];
            A[next] = C[next];
        } else {
            A[next] = A[cur] + A[next];
            A[cur] = 0;
        }
    }
  
    for (int i = 0; i < 3; ++i) 
        printf("%d\n", A[i]);

    return 0;
}
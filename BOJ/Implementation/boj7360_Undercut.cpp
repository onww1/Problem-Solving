#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, A[21], B, as, bs;
int main(int argc, char *argv[]) {
  while (1) {
    if (N) puts("");
    
    scanf("%d", &N);
    if (!N) break;

    as = bs = 0;
    for (int i = 0; i < N; ++i) scanf("%d", A + i);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &B);
      if (abs(A[i] - B) > 1) {
        if (A[i] > B) as += A[i];
        else bs += B;
      }
      else if (abs(A[i] - B) == 1) {
        if (A[i] < B) {
          if (A[i] == 1) as += 6;
          else as += (A[i] + B);
        }
        else {
          if (B == 1) bs += 6;
          else bs += (A[i] + B);
        }
      }
    }

    printf("A has %d points. B has %d points.\n", as, bs);
  }
}
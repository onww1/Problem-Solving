/*
 *  just implementation
 */

#include <cstdio>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  int n, p[10000];
  vector<int> stack;

  scanf("%d", &n);
  for (int i=0; i<n; ++i) scanf("%d", &p[i]);

  stack.push_back(p[n-1]);
  int idx = n - 2;
  int last;
  for (; idx >= 0; --idx) {
    if (p[idx] > p[idx+1]) {
      stack.push_back(p[idx]);
    } else {
      last = p[idx];
      for (int i = 0; i < stack.size(); ++i) {
        if (stack[i] > last) {
          p[idx] = stack[i];
          stack[i] = last;
          break;
        }
      }
      break;
    }
  }
  
  if (idx == -1) {
    printf("-1\n");
    return 0;
  }

  int i = 0;
  for (++idx; idx < n; ++idx, ++i) {
    p[idx] = stack[i];
  }

  for (i = 0; i < n; ++i)
    printf("%d ", p[i]);
  printf("\n");
  return 0;
}

/*
 *  using next_permutation
 */

// #include <cstdio>
// #include <algorithm>
// using namespace std;

// int main(int argc, char *argv[]) {
//   int n, i;
//   int a[10000];
//   scanf("%d", &n);
//   for (i = 0; i < n; ++i) scanf("%d", a + i);

//   if (next_permutation(a, a+n)) {
//     for (i = 0; i < n; ++i)
//       printf("%d ", a[i]);
//     printf("\n");
//   } else {
//     printf("-1\n");
//   }
//   return 0;
// }
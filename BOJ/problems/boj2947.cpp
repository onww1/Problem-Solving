#include <cstdio>
using namespace std;

int in[5];

void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

void print() {
  for (int i = 0; i < 5; ++i) printf("%d ", in[i]);
  printf("\n");
}

int main(int argc, char *argv[]) {
  int i, j;
  for (i = 0; i < 5; ++i) scanf("%d", in + i);
  for (j = 4; j > 0; --j) {
    for (i = 0; i < j; ++i) {
      if (in[i] > in[i+1]) {
        swap(in[i], in[i+1]);
        print();
      }
    }
  }
  return 0;
}
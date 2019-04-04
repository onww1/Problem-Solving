#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct score {
  char name[11];
  int korean, english, math;
};

bool cmp(score a, score b) {
  if (a.korean == b.korean && a.english == b.english && a.math == b.math) return strcmp(a.name, b.name) < 0;
  else if (a.korean == b.korean && a.english == b.english) return a.math > b.math;
  else if (a.korean == b.korean) return a.english < b.english;
  return a.korean > b.korean;
}

int main(int argc, char *argv[]) {
  int n, k, e, m;
  char name[11];
  score scores[100000];

  scanf("%d", &n);
  for (int i=0; i<n; ++i) {
    scanf("%s %d %d %d", scores[i].name, &scores[i].korean, &scores[i].english, &scores[i].math);
  }

  sort(scores, scores + n, cmp);
  for (int i=0; i<n; ++i) {
    printf("%s\n", scores[i].name);
  }
  return 0;
}
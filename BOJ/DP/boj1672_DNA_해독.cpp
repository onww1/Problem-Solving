#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

typedef pair<char, char> pii;

map<pii, char> dic;
char in[1000050];
int n, len;

void init() {
  scanf("%d %s", &n, in);
  len = strlen(in);
  dic[{'A', 'A'}] = 'A', dic[{'A', 'G'}] = 'C', dic[{'A', 'C'}] = 'A', dic[{'A', 'T'}] = 'G';
  dic[{'G', 'A'}] = 'C', dic[{'G', 'G'}] = 'G', dic[{'G', 'C'}] = 'T', dic[{'G', 'T'}] = 'A';
  dic[{'C', 'A'}] = 'A', dic[{'C', 'G'}] = 'T', dic[{'C', 'C'}] = 'C', dic[{'C', 'T'}] = 'G';
  dic[{'T', 'A'}] = 'G', dic[{'T', 'G'}] = 'A', dic[{'T', 'C'}] = 'G', dic[{'T', 'T'}] = 'T';
}

int main(int argc, char *argv[]) {
  int i;
  init();
  for (i = len - 2; i >= 0; --i) in[i] = dic[{in[i], in[i+1]}];
  return !printf("%c\n", in[0]);
}
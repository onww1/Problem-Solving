#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n, s;
char in[100];

int main(int argc, char *argv[]) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf(" %s", in);
        if (!strcmp(in, "anj")) s = 1;
    }
    puts(s ? "뭐야;" : "뭐야?");    
    return 0;
}
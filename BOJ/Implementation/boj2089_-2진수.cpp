#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

vector <char> v;
char ans[50];
int N, idx;

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    while (N) {
        int m = N / (-2), r = N % (-2);
        if (r == -1) m++, r += 2;
        v.push_back(r + '0');
        N = m;
    }

    if (v.empty()) ans[idx++] = '0';
      
    while (!v.empty()) {
        ans[idx++] = v.back();
        v.pop_back();
    }
    ans[idx] = 0;

    printf("%s\n", ans);
    return 0;
}
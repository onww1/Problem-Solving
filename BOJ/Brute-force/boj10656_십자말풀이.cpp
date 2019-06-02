#include <algorithm>
#include <cstdio>
#include <vector>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

int n, m;
char in[50][51];
vector <pii> ans;

int main(int argc, char *argv[]) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) scanf(" %s", in[i]);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (in[i][j] == '#') continue;
            bool flag = false;
            if (j == 0 || in[i][j - 1] == '#') 
                if (j + 2 < m && in[i][j + 1] == '.' && in[i][j + 2] == '.') 
                    flag = true; 
            if (i == 0 || in[i - 1][j] == '#') 
                if (i + 2 < n && in[i + 1][j] == '.' && in[i + 2][j] == '.')
                    flag = true;
            if (flag) ans.push_back({i + 1, j + 1});
        }
    }
  
    printf("%lu\n", ans.size());
    for (pii p : ans) printf("%d %d\n", p.X, p.Y);
    return 0;
}
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

char in[16], ans[5][62];

int main(int argc, char *argv[]) {
    scanf(" %s", in);
    int len = strlen(in);
    ans[0][0] = ans[1][0] = ans[3][0] = ans[4][0] = '.';
    ans[2][0] = '#';

    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < 4; ++j) {
            ans[0][4 * i + j + 1] = ans[4][4 * i + j + 1] = (j == 1 ? i % 3 == 2 ? '*' : '#' : '.');
            ans[1][4 * i + j + 1] = ans[3][4 * i + j + 1] = (j % 2 == 0 ? i % 3 == 2 ? '*' : '#' : '.');
            if (j == 1) ans[2][4 * i + j + 1] = in[i];
            else if (j == 3) {
                if (i % 3 == 0 || (i % 3 == 1 && i + 1 >= len)) ans[2][4 * i + j + 1] = '#';
                else ans[2][4 * i + j + 1] = '*';
            }
            else ans[2][4 * i + j + 1] = '.';
        }
    }

    for (int i = 0; i < 5; ++i) printf("%s\n", ans[i]);
    return 0;
}
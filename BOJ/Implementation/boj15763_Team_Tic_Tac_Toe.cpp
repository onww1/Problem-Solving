#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;
typedef pair <int, int> pii;

char board[3][4];
int ans[2], check[8][26];

int main(int argc, char *argv[]) {
    for (int i = 0; i < 3; ++i) scanf(" %s", board[i]);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            check[i][board[i][j] - 'A']++;
            check[3 + i][board[j][i] - 'A']++;
        }
        check[6][board[i][i] - 'A']++;
        check[7][board[i][2 - i] - 'A']++;
    }

    set <int> solo;
    set <pii> duo;
    for (int i = 0; i < 8; ++i) {
        int one = -1, two = -1;
        for (int j = 0; j < 26; ++j) {
            if (check[i][j] == 3 && solo.count(j) == 0) {
                solo.insert(j);
                ans[0]++;
            }
            if (check[i][j] == 2) two = j;
            if (check[i][j] == 1) one = j;
        }
        if (two < one) swap(one, two);
        if (one != -1 && duo.count({one, two}) == 0) {
            duo.insert({one, two});
            ans[1]++;
        }
    }
  
    printf("%d\n%d\n", ans[0], ans[1]);
    return 0;
}
#include <cstdio>
#include <cstring>

char in[53];
int ans, pos[26][2];

bool check(int a, int b) {
    return pos[a][0] < pos[b][0] && pos[b][0] < pos[a][1] && pos[a][1] < pos[b][1];
}

int main(int argc, char *argv[]) {
    scanf(" %s", in);
    memset(pos, -1, sizeof(pos));
    for (int i = 0; i < 52; ++i) {
        if (pos[in[i] - 'A'][0] == -1) pos[in[i] - 'A'][0] = i;
        else pos[in[i] - 'A'][1] = i;
    }

    for (int i = 0; i < 25; ++i) {
        for (int j = i + 1; j < 26; ++j) {
            if (check(i, j) || check(j, i))
                ans++;
        }
    }
  
    printf("%d\n", ans);
    return 0;
}
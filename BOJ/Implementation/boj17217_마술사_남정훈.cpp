#include <iostream>
#include <cstdio>
using namespace std;

int M, pos, shift, E, R;
char in[27], change[2][2][128], op, shape, A[] = "SDHC";

void init() {
    change[0][0]['S'] = 'S'; change[0][0]['D'] = 'D';
    change[0][0]['H'] = 'H'; change[0][0]['C'] = 'C';
    change[1][0]['S'] = 'C'; change[1][0]['D'] = 'H';
    change[1][0]['H'] = 'D'; change[1][0]['C'] = 'S';
    change[0][1]['S'] = 'H'; change[0][1]['D'] = 'C';
    change[0][1]['H'] = 'S'; change[0][1]['C'] = 'D';
    change[1][1]['S'] = 'D'; change[1][1]['D'] = 'S';
    change[1][1]['H'] = 'C'; change[1][1]['C'] = 'H';
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> M >> in;
    init();

    while (M--) {
        cin >> op;
        if (op == 'E') E ^= 1;
        else if (op == 'R') R ^= 1;
        else if (op == 'G') {
            cin >> pos;
            shift = (shift + pos) % 26;
        }
        else if (op == 'T') {
            cin >> pos >> shape;
            pos = (--pos + 26 - shift) % 26;
            in[pos] = change[E][R][shape];
        }
        else if (op == 'A') {
            if (E || R) for (int i = 0; i < 26; ++i) in[i] = change[E][R][in[i]];
            if (shift) {
                printf("%s", in + 26 - shift);
                char tmp = in[26 - shift];
                in[26 - shift] = 0;
                printf("%s\n", in);
                in[26 - shift] = tmp;
            }
            else printf("%s\n", in);
            E = R = 0;
        }
    }

    return 0;
}

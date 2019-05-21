#include <algorithm>
#include <cstdio>
using namespace std;

int m[4], c[4], dx, dy;

int main(int argc, char *argv[]) {
    for (int i = 0; i < 4; ++i) scanf("%d", m + i);
    for (int i = 0; i < 4; ++i) scanf("%d", c + i);

    if (c[1] <= m[1] && m[3] <= c[3]) {
        if (c[0] <= m[0]) dx = min(m[2] - m[0], max(0, m[2] - c[2]));
        else if (m[2] <= c[2]) dx = min(m[2] - m[0], max(0, c[0] - m[0]));
        else dx = m[2] - m[0];
    } 
    else dx = m[2] - m[0];

    if (c[0] <= m[0] && m[2] <= c[2]) {
        if (c[1] <= m[1]) dy = min(m[3] - m[1], max(0, m[3] - c[3]));
        else if (m[3] <= c[3]) dy = min(m[3] - m[1], max(0, c[1] - m[1]));
        else dy = m[3] - m[1];
    } 
    else dy = m[3] - m[1];

    printf("%d\n", dx * dy);
    return 0;
}
#include <algorithm>
#include <cstdio>
using namespace std;

int x[3][2], y[3][2];

int main(int argc, char *argv[]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            scanf("%d %d", x[i] + j, y[i] + j);
        }
    }

    int area1 = (x[0][1] - x[0][0]) * (y[0][1] - y[0][0]);
    int area2 = (x[1][1] - x[1][0]) * (y[1][1] - y[1][0]);
    int area3 = max(0, min(x[0][1], x[2][1]) - max(x[0][0], x[2][0])) * max(0, min(y[0][1], y[2][1]) - max(y[0][0], y[2][0]));
    int area4 = max(0, min(x[1][1], x[2][1]) - max(x[1][0], x[2][0])) * max(0, min(y[1][1], y[2][1]) - max(y[1][0], y[2][0]));
    printf("%d\n", area1 + area2 - area3 - area4);
    
    return 0;
}
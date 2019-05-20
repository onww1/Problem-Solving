#include <algorithm>
#include <cstdio>
using namespace std;

int main(int argc, char *argv[]) {
	int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    printf("%d\n", min({abs(b - a), abs(c - a) + abs(d - b), abs(d - a) + abs(c - b)}));
    return 0;
}
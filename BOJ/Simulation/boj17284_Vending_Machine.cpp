#include <cstdio>
int main(int argc, char *argv[]) {
    int ans = 5000, choice = 0;
    while (~scanf("%d", &choice)) {
        if (choice == 1) ans -= 500;
        else if (choice == 2) ans -= 800;
        else if (choice == 3) ans -= 1000;
    }
    printf("%d\n", ans);
    return 0;
}
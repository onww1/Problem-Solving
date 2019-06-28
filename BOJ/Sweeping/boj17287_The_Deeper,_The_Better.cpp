#include <algorithm>
#include <cstdio>
using namespace std;

int main(int argc, char *argv[]) {
    char in[105]{};
    int val = 0, mx = 0;
    scanf(" %s", in);

    for (int i = 0; in[i]; ++i) {
        if (in[i] == '(') val += 1;
        else if (in[i] == '{') val += 2;
        else if (in[i] == '[') val += 3;
        else if (in[i] == ']') val -= 3;
        else if (in[i] == '}') val -= 2;
        else if (in[i] == ')') val -= 1;
        else mx = max(mx, val);
    }

    printf("%d\n", mx);
    return 0;
}
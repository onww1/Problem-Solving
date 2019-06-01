#include <cstdio>
using namespace std;
typedef long long ll;

const int MAX = 1e5 + 1;
ll n, cow[3];
char in[MAX];

int main(int argc, char *argv[]) {
    scanf("%lld %s", &n, in);
    for (int i = 0; in[i]; ++i) {
        if (in[i] == 'C') ++cow[0];
        else if (in[i] == 'O') cow[1] += cow[0];
        else cow[2] += cow[1];
    }
    printf("%lld\n", cow[2]); 
    return 0;
}
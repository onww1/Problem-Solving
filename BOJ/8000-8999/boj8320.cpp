#include <cstdio>
using namespace std;

int main(int argc, char *argv[]) {
    int N, ans = 0;
    scanf("%d", &N);
    for (int i = 1, j; i <= N; ++i) {
    	for (j = 1; j * j < i; ++j) 
    		if (i % j == 0) ans++;
    	if (j * j == i) ans++;
    } 
    
    printf("%d\n", ans);
    return 0;
}
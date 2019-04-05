#include <cstdio>
using namespace std;

int main() {
    int M, N;
    scanf("%d %d", &M, &N);
    
    int sum = 0;
    int min = 10001;
    
    for(int i=1; i<=100; i++) {
    	int mul = i * i;
        if( M <= mul && mul <= N ) {
            sum += mul;
            if( min == 10001 ) min = mul;
        }
        else if( mul > N ) break;
    }
    
    if( sum == 0 ) printf("-1\n");
    else printf("%d\n%d\n", sum, min);
    return 0;
}
#include <cstdio>
using namespace std;

int main() {
    int t, n;
    long arr[101] = {0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9, };
    for(int i=11; i<=100; i++){
        arr[i] = arr[i-1] + arr[i-5];
    }
    
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        printf("%ld\n", arr[n]);
    }
    return 0;
}
#include <stdio.h>

int main(void){
    int t, n, idx, remainder;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        idx = 0;
        while(n > 0){
            remainder = n%2;
            n/=2;
            
            if(remainder) {
                if(n>0) printf("%d ", idx);
                else if(n==0) printf("%d\n", idx);
            }
            idx++;
        }
    }

    return 0;
}
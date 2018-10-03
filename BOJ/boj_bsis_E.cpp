#include <cstdio>
using namespace std;

int main(void)
{
    int n, max = 0;
    int a[100000], b[1000001] = {0, };
    
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
    
    for(int i=0; i<=1000000; i++)
        b[i] = 0;

    for(int i=0; i<n; i++)
    {
        b[a[i]] = b[a[i]-1] + 1;
        if(max < b[a[i]]) max = b[a[i]];
    }

    printf("%d\n", max);
    return 0;
}
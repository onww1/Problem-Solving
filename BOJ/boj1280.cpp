#include <cstdio>
#define MOD 1000000007

int n;
int pos[200001] = {0, };

int main(void){
	long long cost = 1; 
	scanf("%d", &n);

	scanf("%d", &pos[1]);

	for(int i=2; i<=n; i++){
		scanf("%d", &pos[i]);
		long long val = 0;
		for(int j=1; j<i; j++){
			val += (pos[i] > pos[j]? (long long)(pos[i]-pos[j]):(long long)(pos[j]-pos[i]));
		}
		cost = (cost * val)%MOD;
	}
	printf("%lld\n", cost);
	return 0;
}
#include <cstdio>

int max = -1e9 - 1, min = 1e9 + 1;
int n, a[11], o[4];

void solve(int add, int sub, int mul, int div, int val, int cnt){
	if( cnt == n-1 ){
		if(add) val += a[cnt];
		if(sub) val -= a[cnt];
		if(mul) val *= a[cnt];
		if(div) val /= a[cnt];
		if(val > max) max = val;
		if(val < min) min = val;
		return;
	}

	if(add) solve( add - 1, sub, mul, div, val + a[cnt], cnt + 1 );
	if(sub) solve( add, sub - 1, mul, div, val - a[cnt], cnt + 1 );
	if(mul) solve( add, sub, mul - 1, div, val * a[cnt], cnt + 1 );
	if(div) solve( add, sub, mul, div - 1, val / a[cnt], cnt + 1 );
}

int main(void){
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", &a[i]);
	scanf("%d %d %d %d", &o[0], &o[1], &o[2], &o[3]);

	solve(o[0], o[1], o[2], o[3], a[0], 1);	
	printf("%d\n%d\n", max, min);
	return 0;
}
#include <stdio.h>

int abs2(int a, int b){
	return (a>b)?(a-b):(b-a);
}

int main(void){
	int a[2], b[2], c[2], d[2], cnt;
	while(1){
		scanf("%d %d %d %d", &a[0], &b[0], &c[0], &d[0]);
		if(!a[0] && !b[0] && !c[0] && !d[0]) break;
		cnt = 0;
		while(1){
			if(a[0] == b[0] && b[0] == c[0] && c[0] == d[0]) break;
			a[1] = abs2(a[0], b[0]);
			b[1] = abs2(b[0], c[0]);
			c[1] = abs2(c[0], d[0]);
			d[1] = abs2(d[0], a[0]);
			a[0] = a[1];
			b[0] = b[1];
			c[0] = c[1];
			d[0] = d[1];
			cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
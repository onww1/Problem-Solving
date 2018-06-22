#include <stdio.h>

int main(void){
	long yb, bb, y, g, b;
	scanf("%ld %ld %ld %ld %ld", &yb, &bb, &y, &g, &b);

	yb -= 2*y + g;
	bb -= g + 3*b;
	if(yb > 0) yb = 0;
	else yb = 0 - yb;

	if(bb > 0) bb = 0;
	else bb = 0 - bb;

	printf("%ld\n", yb + bb);
	return 0;
}
#include <stdio.h>
#include <math.h>

int isSquare(long val){
	long root = (long)floor(sqrt(val));
	if(root * root == val) return 1;
	else return 0;
}

int check(long cur, long prevSquare){
	long root = (long)ceil(sqrt(prevSquare));
	if(root == cur) return 1;
	else return 0;
}

int main(void){
	long g, cur, square, prev;
	int flag=0;
	
	scanf("%ld", &g);
	cur = (long)ceil(sqrt((int)g));

	while(1){
		square = cur * cur;
		prev = square - g;
		if(isSquare(prev)) {
			printf("%ld\n", cur);
			flag = 1;
		} else if(check(cur, prev)) {
			break;
		}
		cur++;
	}
	if(!flag) printf("-1\n");
	return 0;
}
#include <cstdio>

int main(void){
	long min, max, cnt = 0, i=2, square, arr[1000001] = {0};
	scanf("%ld %ld", &min, &max);
	while(1){
		square = i*i;
		if(square*2 > max) break;
		for(long j=0; j<=(max-min); j++){
			if(arr[j]) continue;
			if((min+j)%square == 0) {arr[j] = 1; cnt++;}
		}
		i++;
	}
	long result = max-min+1-cnt;
	if(min == 1) result -= 1;
	printf("%ld\n", result);
	return 0;
}
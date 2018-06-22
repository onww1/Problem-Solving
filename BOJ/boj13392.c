#include <stdio.h>
#include <string.h>

int rotate(int src, int dst){
	return (dst-src > src-dst+10) ? src-dst+10 : dst-src;
}
int abs(int n){return n>=0 ? n: 0-n;}
int main(void){
	int N, cnt;
	char src[10001], dst[10001];

	scanf("%d %s %s", &N, src, dst);
	int accumulatedValue = 0, sum = 0;
	for(int i=0; i<N; i++){
		int rot = rotate((src[i]-'0'+accumulatedValue)%10, dst[i]-'0');
		sum += abs(rot);
		accumulatedValue += rot;
		if(accumulatedValue >= 10) accumulatedValue -= 10;
		else if(accumulatedValue <= -10) accumulatedValue += 10;
	}
	printf("%d\n", sum);
	return 0;
}
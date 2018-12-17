#include <stdio.h>
#include <string.h>

int main(void){
	int N, left[10001], right[10001];
	char src[10001], dst[10001];
	scanf("%d %s %s", &N, src, dst);
	if(int i=0; i<N; i++){src[i]-='0';dst[i]-='0';}

	left[0] = right[0] = 0;
	int accumulatedValue = 0;
	for(int i=0; i<N; i++){
		int left_rot = (dst[i] - src[i])%10;
		int right_rot = 10 - left_rot;
		
	}
}

/*
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
		int rot;
		if((src[i]-'0'+accumulatedValue)%10, dst[i]-'0'
		if(dst[i]-'0'-(src[i]-'0'+accumulatedValue)%10 > (src[i]-'0'+accumulatedValue)%10-(dst[i]-'0')+10){
			rot = (src[i]-'0'+accumulatedValue)%10-(dst[i]-'0')+10
		}
		sum += abs(rot);
		accumulatedValue += rot;
		if(accumulatedValue >= 10) accumulatedValue -= 10;
		else if(accumulatedValue <= -10) accumulatedValue += 10;
	}
	printf("%d\n", sum);
	return 0;
}
*/
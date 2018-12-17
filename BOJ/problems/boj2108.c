#include <stdio.h>
#include <stdlib.h>

int main(void){
	int N;
	scanf("%d", &N);
	int* arr = (int*)malloc(sizeof(int) * N);
	int cnt[8001] = {0}, acnt[8001] = {0};
	for(int i=0; i<N; i++){
		scanf("%d", &arr[i]);
		cnt[arr[i] + 4000]++;
	}
	acnt[0] = cnt[0];
	for(int i=1; i<=8000; i++) acnt[i] = acnt[i-1] + cnt[i];
	for(int i=0, j=0; i<N; j++){
		if(j==0 && i<acnt[j])while(i<acnt[j]){arr[i] = j-4000; i++;}
		else while(acnt[j-1]<=i && i<acnt[j]){arr[i] = j-4000; i++;}
	}

	// average
	int sum = 0, avg;
	for(int i=0; i<=8000; i++) sum += cnt[i] * (i-4000);
	avg = (sum/N) + ((sum<0)?(((0-sum)%N == 0)?0:-1):0) + (((((sum%N)+N)%N)*2 >= N)?1:0);

	// median
	int median = arr[(N-1)/2];

	// mode
	int freq[2] = {-10000, -10000};
	int max = -1, mode;
	for(int i=8000; i>=0; i--){
		if(cnt[i] > max){
			freq[0] = i-4000;
			freq[1] = -10000;
			max = cnt[i];
		} else if(cnt[i] == max){
			freq[1] = freq[0];
			freq[0] = i-4000;
		}
	}
	mode = (freq[1] == -10000)?freq[0]:freq[1];

	// range
	int range = arr[N-1] - arr[0];

	printf("%d\n%d\n%d\n%d\n", avg, median, mode, range);

	free(arr);
	return 0;
}
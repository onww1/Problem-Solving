#include <stdio.h>

int main(void){
	int arr[16], ptr, len, i, cnt;
	while(1){
		cnt = 0;
		for(len=0; len<16; len++){
			scanf("%d", &arr[len]);
			if(arr[len] == 0) break;
			if(arr[0] == -1) return 0;
		}
		for(i=0; i<len-1; i++){
			for(ptr=i+1; ptr<len; ptr++){
				if(arr[i] == 2*arr[ptr] || arr[ptr] == 2*arr[i]) cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
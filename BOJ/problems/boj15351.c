#include <stdio.h>
#include <string.h>

int main(void){
	int N, score;
	char str[31];

	scanf("%d\n", &N);
	while(N--){
		score = 0;
		gets(str);
		int len = strlen(str);
		for(int i=0; i<len; i++)
			if(str[i] != ' ') score += str[i] - 'A' + 1;
		if(score == 100) printf("PERFECT LIFE\n");
		else printf("%d\n", score);
	}
	return 0;
}
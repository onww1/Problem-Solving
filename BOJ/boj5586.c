#include <stdio.h>
#include <string.h>

int main(void){
	char input[10001];
	scanf("%s", input);
	int cntJ = 0, cntI = 0;
	int stateJ = 0, stateI = 0;
	int len = strlen(input);
	for(int i=0; i<len; i++){
		if(input[i] == 'J'){
			stateJ = 1;
			stateI = 0;
		} else if(input[i] == 'O'){
			if(stateJ == 1) stateJ = 2;
			else stateJ = 0;

			if(stateI == 1) stateI = 2;
			else stateI = 0;
		} else if(input[i] == 'I'){
			if(stateJ == 2) cntJ++;
			stateJ = 0;

			if(stateI == 0) stateI = 1;
			else if(stateI == 2){ stateI = 1; cntI++; }
			else stateI = 1;
		} else {stateI = stateJ = 0;}
	}
	printf("%d\n%d\n", cntJ, cntI);
	return 0;
}
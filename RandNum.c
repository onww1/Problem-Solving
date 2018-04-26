#include <Turboc.h>

void main(){
	int num, input;

	randomize();
	for(;;){
		num = random(100)+1;
		printf("\npredict\n");
		do {
			printf("input(if you want to exit, then input 999) : ");
			scanf("%d", &input);
			if(input == 999) exit(0);
			if(input == num) printf("correct\n");
			else if(input > num) printf("up\n");
			else printf("down\n");
		} while(input!=num);
	}
}
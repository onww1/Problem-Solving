#include <stdio.h>

int numberCount(int number, int what){
	int sum = 0, remainder;
	while(number > 0){
		remainder = number%what;
		number /= what;
		sum += remainder;
	}
	return sum;
}

int main(void){
	int value;
	for(int i=1000; i<10000; i++){
		value = numberCount(i, 16);
		if(value == numberCount(i, 12)){
			if(value == numberCount(i, 10)){
				printf("%d\n", i);
			}
		}
	}
	return 0;
}
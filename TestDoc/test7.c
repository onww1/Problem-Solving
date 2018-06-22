#include <stdio.h>

int main(void){
	for(int i=0; i<10; i++){
		if( i % 2 == 0 ){
			int a = i;
			printf("%d %p\n", a, &a);
		}
		else if( i % 2 == 1 ){
			int a = i;
			printf("%d %p\n", a, &a);
		}
	}	
	return 0;
}

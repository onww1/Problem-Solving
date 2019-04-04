#include <stdio.h>
#include <string.h>

char plain(char c){
	return (c + 'V' - 'A' * 2) % 26 + 'A';
}

int main(void){
	char input[202];
	int len;

	while(1){
		gets(input);
		if(strcmp(input, "ENDOFINPUT") == 0) break;

		gets(input);
		len = strlen(input);
		for(int i=0; i<len; i++){
			if('A' <= input[i] && input[i] <= 'Z')
				input[i] = plain(input[i]);
		}
		printf("%s\n", input);

		gets(input);
	}

	return 0;
}
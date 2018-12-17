#include <cstdio>
#include <cstring>

char plain(char c){
	return (c + 'V' - 2 * 'A') % 26 + 'A';
}

int main(void){
	char input[202];

	while(1){
		fgets(input, 202, stdin);
		int len = strlen(input);
		input[len-1] = '\0';
		if(strcmp(input, "ENDOFINPUT") == 0) break;

		fgets(input, 202, stdin);
		len = strlen(input);
		input[len-1] = '\0';
		len--;
		for(int i=0; i<len; i++){
			if(input[i] >= 'A' && input[i] <= 'Z')
				input[i] = plain(input[i]);
		}
		printf("%s\n", input);

		fgets(input, 202, stdin);
	}

	return 0;
}
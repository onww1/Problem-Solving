#include <stdio.h>
#include <string.h>

int isVowel(char c){
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return 1;
	return 0;
}

int hasVowel(char* password){
	int len = strlen(password);
	for(int i=0; i<len; i++){
		if(isVowel(password[i])) return 1;
	}
	return 0;
}

int checkTriple(char* password){
	int len = strlen(password);
	int type = 0, cnt = 0;
	for(int i=0; i<len; i++){
		if(isVowel(password[i])){
			if(type == 0) cnt++;
			else{
				type = 0;
				cnt = 1;
			}
		} else {
			if(type == 0){
				type = 1;
				cnt = 1;
			} else cnt++;
		}
		if(cnt == 3) return 1;
	}
	return 0;
}

int checkTwice(char* password){
	int len = strlen(password);
	int prev = password[0];
	for(int i=1; i<len; i++){
		if(password[i] == prev) {
			if(password[i] == 'e' || password[i] == 'o') continue;
			else return 1;
		}
		else prev = password[i];
	}
	return 0;
}

int main(void){
	char password[21];
	while(1){
		scanf("%s", password);
		if(strcmp(password, "end") == 0) break;

		if(hasVowel(password) && !checkTriple(password) && !checkTwice(password))
			printf("<%s> is acceptable.\n", password);
		else printf("<%s> is not acceptable.\n", password);
	}

	return 0;
}
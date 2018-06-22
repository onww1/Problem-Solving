#include <stdio.h>
#include <string.h>

void addBinary(char* input1, char* input2, int len1, int len2, char* result){
	int diff = len1 - len2;
	for(int i=len2-1; i>=0; i--){
		result[diff+i+1] += input1[diff+i] + input2[i] - '0';
		if(result[diff+i+1] > '1'){
			result[diff+i+1]-=2;
			result[diff+i] += 1; 
		}
	}
	for(int i=len1-len2-1; i>=0; i--){
		result[i+1] += input1[i];
		if(result[i+1] > '1'){
			result[i+1]-=2;
			result[i] += 1;
		}
	}
	result[diff+len2+1] = '\0';
}

void printBinary(char* binary){
	if(binary[0] == '\0') binary[0] = '0';
	int len = strlen(binary);
	int i = 0;
	while(binary[i] == '0') i++;
	if(i == len){printf("0\n"); return;}
	for(;i<len; i++) printf("%c", binary[i]);
	printf("\n");
}

int main(void){
	char input1[81], input2[81], result[82] = {0};
	int len1, len2;
	scanf("%s %s", input1, input2);
	len1 = strlen(input1);
	len2 = strlen(input2);
	if(len1 > len2) addBinary(input1, input2, len1, len2, result);
	else addBinary(input2, input1, len2, len1, result);
	printBinary(result);
	return 0;
}

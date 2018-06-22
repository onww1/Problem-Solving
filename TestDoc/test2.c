#include <stdio.h>
#include <string.h>

void reverse(char* input, int len){
	for(int i=0; i<len/2; i++){
		char temp = input[i];
		input[i] = input[len-1-i];
		input[len-1-i] = temp;
	}
	return;
}
void print_binary(char* input, int len){
	int flag = 0, i;
	for(i=0; i<len; i++){
		if(input[i] == 0 && !flag) continue;
		else{
			flag = 1;
			printf("%d", input[i]);
		}
	}
	if(flag == 0 && i == len) printf("0");
	printf("\n");
}
int main(void){
	char binary1[81], binary2[81];
	char result[81] = {0};
	int len1, len2, len;
	scanf("%s %s", binary1, binary2);
	len1 = strlen(binary1);
	len2 = strlen(binary2);
	reverse(binary1, len1);
	reverse(binary2, len2);
	for(int i=0; i<80; i++){
		if(i<len1 && i<len2){
			result[i] += (binary1[i]-'0')+(binary2[i]-'0');
			if(result[i] > 1){
				result[i+1] += result[i]/2;
				result[i] %= 2; 
			}
		} else if(i<len2){
			result[i] += (binary2[i]-'0');
			if(result[i] > 1){
				result[i+1] += result[i]/2;
				result[i] %= 2; 
			}
		} else if(i<len1){
			result[i] += (binary1[i]-'0');
			if(result[i] > 1){
				result[i+1] += result[i]/2;
				result[i] %= 2;
			}
		} else{
			if(result[i] != 0) i++;
			len = i;
			break;
		}
	}
	reverse(result, len);
	print_binary(result, len);
	return 0;
}
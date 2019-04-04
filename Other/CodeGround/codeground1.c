#include <stdio.h>

int okay(char s, char d){
	if(s<d) return 1;
	else return 0;
	return 0;
}

int main(void){
	int t, cnt, flag;
	char input[8][9];
	char c[8][8];
	scanf("%d", &t);
	while(t--){
		flag = 1;
		for(int i=0; i<8; i++)
			scanf("%s", input[i]);
		for(int i=0; i<8; i++)
			for(int j=0; j<8; j++)
				c[i][j] = 0;
		for(int i=0; i<8; i++){
			for(int j=0; j<8; j++){
				if(input[i][j] == 'Z'){
					if(i>0 && input[i-1][j]=='A'){c[i][j] += 8; c[i][j] += 16;}
					if(i<n-1 && input[i+1][j] =='A') {c[i][j] += 4; c[i][j] += 16;}
					if(j>0 && input[i][j-1]=='A'){c[i][j] += 2; c[i][j] += 16;}
					if(j<n-1 && input[i][j+1] =='A') {c[i][j] += 1; c[i][j] += 16;}
				}else{
					if(i>0 && input[i-1][j] > input[i][j]) c[i][j] += 8;
					if(i<n-1 && input[i+1][j] > input[i][j]) c[i][j] += 4;
					if(j>0 && input[i][j-1] > input[i][j]) c[i][j] += 2;
					if(j<n-1 && input[i][j+1] > input[i][j]) c[i][j] += 1;
				}

			}
		}
	}
}
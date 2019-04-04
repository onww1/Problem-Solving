#include <cstdio>
#include <cstdlib>

char sudoku[9][9] = {0, };

void go(int pos){
	int row = pos/9;
	int col = pos%9;
	if(pos == 81) {
		for(int i=0; i<9; i++){
			for(int j=0; j<8; j++){
				printf("%d ", sudoku[i][j]);
			}
			printf("%d\n", sudoku[i][8]);
		}
		exit(0);
	}
	if(sudoku[row][col]){
		go(pos+1);
		return;
	}

	bool num[10];
	for(int i=1; i<=9; i++) num[i] = true;
	for(int i=0; i<9; i++) {
		num[sudoku[i][col]] = false;
		num[sudoku[row][i]] = false;
	}
	for(int i=row/3 * 3; i<row/3 * 3 + 3; i++){
		for(int j=col/3 * 3; j<col/3 * 3 + 3; j++){
			num[sudoku[i][j]] = false;
		}
	}
	for(int i=1; i<=9; i++){
		if(num[i]){
			sudoku[row][col] = i;
			go(pos+1);
			sudoku[row][col] = 0;
		}
	}
}

int main(void){
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			scanf("%hhd", &sudoku[i][j]);
		}
	}

	go(0);
	return 0;
}
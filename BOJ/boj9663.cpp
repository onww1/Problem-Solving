#include <cstdio>

int N, cnt = 0;
int board[15][15] = {0, };
int column[15] = {0, };

int check(int board[][15], int row, int col){
	if(column[col]) return 0;
	for(int i=1; row>=i; i++){
		if( col-i>=0 && board[row-i][col-i] ) return 0;
		if( col+i<N  && board[row-i][col+i] ) return 0;
	}
	return 1;
}

void go(int board[][15], int num){
	for(int i=0; i<N; i++){
		if(check(board, num, i)){
			if(num == N-1) {
				cnt++;
			}
			else {
				board[num][i] = 1;
				column[i] = 1;
				go(board, num+1);
				column[i] = 0;
				board[num][i] = 0;
			}
		}
	}
}

int main(void){
	scanf("%d", &N);
	go(board, 0);
	printf("%d\n", cnt);
	return 0;
}
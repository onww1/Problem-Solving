#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int N, M;
	char map[50][51];
	char board[8][8];

	for (int i=0; i<8; i++) {
		for (int j=0; j<8; j++) {
			if ( (i + j) % 2 ) {
				board[i][j] = 'B';
			}
			else {
				board[i][j] = 'W';
			}
		}
	}

	scanf("%d %d", &N, &M);
	for (int i=0; i<N; i++)
		scanf("%s", map[i]);

	int min = 987654321;
	for (int i=0; i<N-7; i++) {
		for (int j=0; j<M-7; j++) {
			int wcnt = 0, bcnt = 0;
			for (int r=0; r<8; r++) {
				for (int c=0; c<8; c++) {
					if (map[i+r][j+c] == board[r][c])
						bcnt++;
					else
						wcnt++;
				}
			}
			min = min > bcnt ? bcnt : min;
			min = min > wcnt ? wcnt : min;
		}
	}

	cout << min << '\n';

	return 0;
}
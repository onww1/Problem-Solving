#include <cstdio>
#include <cstring>

int r, c, cnt=1, maxCnt=0;
int alphabet[26] = {0, };
char map[20][21] = {0, };

void dfs(int row, int col){
	if(row > 0 && !alphabet[map[row - 1][col] - 'A']){
		cnt++; 
		alphabet[map[row-1][col] -'A'] = 1;
		dfs(row-1, col);
	}
	if(row < r-1 && !alphabet[map[row + 1][col] - 'A']){
		cnt++; 
		alphabet[map[row+1][col] -'A'] = 1;
		dfs(row+1, col);
	}
	if(col > 0 && !alphabet[map[row][col - 1] - 'A']){
		cnt++; 
		alphabet[map[row][col-1] -'A'] = 1;
		dfs(row, col-1);
	}
	if(col < c-1 && !alphabet[map[row][col + 1] - 'A']){
		cnt++; 
		alphabet[map[row][col+1] -'A'] = 1;
		dfs(row, col+1);
	}

	if(cnt > maxCnt) maxCnt = cnt;
	cnt--;
	alphabet[map[row][col] -'A'] = 0;
}

int main(void){
	scanf("%d %d", &r, &c);
	for(int i=0; i<r; i++){
			scanf("%s", map[i]);
	}

	alphabet[map[0][0] -'A'] = 1;
	dfs(0, 0);

	printf("%d\n", maxCnt);
	return 0;
}
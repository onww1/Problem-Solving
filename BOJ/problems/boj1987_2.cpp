#include <cstdio>
using namespace std;

int R, C, global_max = 1, local_max = 1;
int move_r[] = {-1, 1, 0, 0};
int move_c[] = {0, 0, -1, 1};
char map[20][21];
bool visited[26] = {false, };

int check(int r, int c){
	if(r < 0 || r >= R || c < 0 || c >= C) return false;
	return true;
}

void dfs(int r, int c){
	visited[map[r][c] - 'A'] = true;
	for(int k=0; k<4; k++){
		int dr = r + move_r[k];
		int dc = c + move_c[k];

		if(check(dr, dc) && !visited[map[dr][dc] - 'A']){
			local_max++;
			if(local_max > global_max) global_max = local_max;
			dfs(dr, dc);
		}
	}
	visited[map[r][c] - 'A'] = false;
}

int main(void){
	scanf("%d %d", &R, &C);
	getchar();

	for(int i=0; i<R; i++)
		scanf("%s", map[i]);

	dfs(0, 0);
	printf("%d\n", global_max);

	return 0;
}
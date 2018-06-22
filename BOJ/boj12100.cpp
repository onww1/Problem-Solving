#include <cstdio>
#include <deque>

int N;
int board[20][20] = {0, };

int max2(int a, int b){ return a>b?a:b; }
int max4(int a, int b, int c, int d){
	int m1 = max2(a, b);
	int m2 = max2(c, d);
	return max2(m1, m2);
}

int go(int arr[][20], int d, int cnt){
	std::deque<int> stk;
	int board[20][20];
	int prev = 0;

	for(int i=0; i<N; i++) for(int j=0; j<N; j++) board[i][j] = arr[i][j];

	if(d == 0){ // left
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				if(board[i][j]){
					if(!stk.empty() && stk.back() == board[i][j] && prev != board[i][j]){
						int tmp = (board[i][j] << 1);
						stk.pop_back();
						stk.push_back(tmp);
						prev = tmp;
					} else {
						prev = 0;
						stk.push_back(board[i][j]);
					}
				}
			}

			int stkSize = stk.size();
			for(int j=0; j<N; j++){
				if(j < stkSize){ 
					board[i][j] = stk.front();
					stk.pop_front();
				} else board[i][j] = 0;
			}
		}
	} else if(d == 1){ // right
		for(int i=0; i<N; i++){
			for(int j=N-1; j>=0; j--){
				if(board[i][j]){
					if(!stk.empty() && stk.back() == board[i][j] && prev != board[i][j]){
						int tmp = (board[i][j] << 1);
						stk.pop_back();
						stk.push_back(tmp);
						prev = tmp;
					} else {
						prev = 0;
						stk.push_back(board[i][j]);
					}
				}
			}

			int stkSize = stk.size();
			for(int j=N-1; j>=0; j--){
				if(j >= N - stkSize){ 
					board[i][j] = stk.front();
					stk.pop_front();
				} else board[i][j] = 0;
			}
		}
	} else if(d == 2){ // up
		for(int j=0; j<N; j++){
			for(int i=0; i<N; i++){
				if(board[i][j]){
					if(!stk.empty() && stk.back() == board[i][j] && prev != board[i][j]){
						int tmp = (board[i][j] << 1);
						stk.pop_back();
						stk.push_back(tmp);
						prev = tmp;
					} else {
						prev = 0;
						stk.push_back(board[i][j]);
					}
				}
			}

			int stkSize = stk.size();
			for(int i=0; i<N; i++){
				if(i < stkSize){ 
					board[i][j] = stk.front();
					stk.pop_front();
				} else board[i][j] = 0;
			}
		}
	} else if(d == 3){ // down
		for(int j=0; j<N; j++){
			for(int i=N-1; i>=0; i--){
				if(board[i][j]){
					if(!stk.empty() && stk.back() == board[i][j] && prev != board[i][j]){
						int tmp = (board[i][j] << 1);
						stk.pop_back();
						stk.push_back(tmp);
						prev = tmp;
					} else {
						prev = 0;
						stk.push_back(board[i][j]);
					}
				}
			}

			int stkSize = stk.size();
			for(int i=N-1; i>=0; i--){
				if(i >= N - stkSize){ 
					board[i][j] = stk.front();
					stk.pop_front();
				} else board[i][j] = 0;
			}
		}
	}

	// printf("cnt : %d, direction : %d\n", cnt, d);
	// for(int i=0; i<N; i++){
	// 	for(int j=0; j<N; j++){
	// 		printf("%d\t", board[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// printf("\n");

	if(cnt == 5){
		int maxVal = 0;
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				if(board[i][j] > maxVal) maxVal = board[i][j];
			}
		}
		return maxVal;
	} else return max4(
					go(board, 0, cnt+1),
					go(board, 1, cnt+1),
					go(board, 2, cnt+1),
					go(board, 3, cnt+1)
					  );
}

int getMaxValue(int board[][20]){
	return max4( 
			go(board, 0, 1),
			go(board, 1, 1),
			go(board, 2, 1),
			go(board, 3, 1)
			   );
}

int main(void){
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%d", &board[i][j]);
		}
	}

	printf("%d\n", getMaxValue(board));
	return 0;
}
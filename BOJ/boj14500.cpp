#include <cstdio>

int max2(int i, int j){ return i>j?i:j; }
int max4(int a, int b, int c, int d){ return max2(max2(a,b),max2(c,d)); }

int main(void){
	int n, m, max = 4;
	int map[500][500];

	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%d", &map[i][j]);
		}
	}

	int sum = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			sum = 0;
			if(j <= m-4){
				sum = map[i][j] + map[i][j+1] + map[i][j+2] + map[i][j+3]; 
				if( sum > max ) max = sum;
			}
			sum = 0;
			if(i <= n-2 && j <= m-2){
				sum = map[i][j] + map[i][j+1] + map[i+1][j] + map[i+1][j+1];
				if( sum > max ) max = sum;
			}
			sum = 0;
			if(i <= n-2 && j <= m-3){
				sum = map[i][j] + map[i+1][j] + map[i][j+1] + map[i+1][j+1] + map[i][j+2] + map[i+1][j+2];
				sum = max2( max4( sum - map[i][j] - map[i][j+1],
								  sum - map[i][j+1] - map[i][j+2],
								  sum - map[i+1][j] - map[i+1][j+1],
								  sum - map[i+1][j+1] - map[i+1][j+2]),
							max4( sum - map[i][j] - map[i+1][j+2],
								  sum - map[i+1][j] - map[i][j+2],
								  sum - map[i][j] - map[i][j+2],
								  sum - map[i+1][j] - map[i+1][j+2]));
				if( sum > max ) max = sum;
			}
			sum = 0;
			if(i <= n-3 && j <= m-2){
				sum = map[i][j] + map[i+1][j] + map[i+2][j] + map[i][j+1] + map[i+1][j+1] + map[i+2][j+1];
				sum = max2( max4( sum - map[i][j] - map[i+1][j],
								  sum - map[i+1][j] - map[i+2][j],
								  sum - map[i][j+1] - map[i+1][j+1],
								  sum - map[i+1][j+1] - map[i+2][j+1]),
							max4( sum - map[i][j] - map[i+2][j+1],
								  sum - map[i][j+1] - map[i+2][j],
								  sum - map[i][j] - map[i+2][j],
								  sum - map[i][j+1] - map[i+2][j+1]));
				if( sum > max ) max = sum;
			}
			sum = 0;
			if(i <= n-4){
				sum = map[i][j] + map[i+1][j] + map[i+2][j] + map[i+3][j];
				if( sum > max ) max = sum;
			}
		}
	}

	printf("%d\n", max);
	return 0;
}
#include <cstdio>

int r, c, dp[15][15];
char in[15][16];

int main(int argc, char *argv[]) {
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; ++i) scanf(" %s", in[i]);
    
    dp[0][0] = 1;
    for (int i = 0; i < r; ++i) 
        for (int j = 0; j < c; ++j) 
            if (dp[i][j]) 
                for (int k = i + 1; k < r; ++k) 
                    for (int l = j + 1; l < c; ++l) 
                        if (in[i][j] != in[k][l]) 
                            dp[k][l] += dp[i][j];
        
    printf("%d\n", dp[r - 1][c - 1]);
    return 0;
}
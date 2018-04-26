#include <stdio.h>
#include <string.h>

int clap(char* input){
	int len = strlen(input);
	int threeMul = 0, n, complement, flag = 0;
	for(int i=0; i<len; i++){
		n = input[i]-'0' + complement;
		threeMul = (threeMul*10 + n/3)%20150523;
		complement = 10*(n%3);
	}

	int dp[100002] = {3}, dp2[100002] = {6}, tsn = 0;
	for(int i=1; i<len-1; i++){
		dp[i] = (dp[i-1] * 10 + dp2[i-1] * 3)%20150523;
		dp2[i] = (dp2[i-1] * 7)%20150523;
	}
	for(int i=len-2; i>=0; i--){
		n = input[i] - '0';
		if(n%3 == 0) flag = 1;
		tsn = (tsn + dp[len-2-i] * n)%20150523;
	}
	if(flag) tsn = (tsn + input[len-1] - '0' + 1) % 20150523;
	else tsn = (tsn + (input[len-1]-'0')/3);

	int cross = 0, dp3[100002] = {0}, dp4[100002] = {6};
	dp2[0] = 0;
	for(int i=1; i<len-1; i++){
		dp[i] = (dp[i-1] * 4 + dp2[i-1] * 6 + dp3[i-1] * 3)%20150523;
		dp2[i] = (dp[i-1] * 6 + dp2[i-1] * 7 + dp4[i-1] * 3)%20150523;
		dp3[i] = (dp3[i-1] + dp4[i-1] * 6)%20150523;
		dp4[i] = (dp3[i-1] * 6 + dp4[i-1] * 4)%20150523;
	}
	for(int i=len-2; i>=0; i--){
		n = input[i] - '0';
		cross = (cross + dp[len-2-i] * n)%20150523;
	}
	printf("%d %d %d %d %d %d\n", dp[0], dp[1], dp[2], dp[3], dp[4], cross);
	int result = (threeMul + tsn - cross)%20150523;
	return result;
}

int main(void){
	char inputA[100002], inputB[100002];
	int len;
	scanf("%s %s", inputA, inputB);
	len = strlen(inputA);
	for(int i=len-1; i>=0; i--){
		inputA[i] -= 1;
		if(inputA[i] < '0') inputA[i] += 10;
		else break;
	}
	printf("inputA %d\ninputB %d\nB-A %d\n", clap(inputA), clap(inputB), clap(inputB)-clap(inputA));
	int result = (clap(inputB)-clap(inputA))%20150523;
	printf("result %d\n", result);
	return 0;
}
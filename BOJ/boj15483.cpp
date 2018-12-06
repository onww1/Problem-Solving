#include <iostream>
#include <vector>
#include <string>
using namespace std;

string str1, str2;
vector< vector<int> > dp;
int len1, len2;

int get_min(int a, int b) { return a < b ? a : b; }

void input() {
	cin >> str1 >> str2;
	len1 = str1.length();
	len2 = str2.length();
	dp.resize(len1 + 1, vector<int>(len2 + 1, -1));
	dp[0][0] = 0;
	for (int i=1; i<=len1; i++) dp[i][0] = i;
	for (int j=1; j<=len2; j++) dp[0][j] = j;
}

int getAnswer(int apos, int bpos) {
	int& ret = dp[apos][bpos];
	if (ret != -1) return ret;
	if (str1[apos-1] == str2[bpos-1]) return ret = getAnswer(apos-1, bpos-1);
	else {
		return ret = min(getAnswer(apos, bpos-1), min(getAnswer(apos-1, bpos), getAnswer(apos-1, bpos-1))) + 1;
	}
}

void process() {
	getAnswer(len1, len2);
}

void output() {
	cout << dp[len1][len2] << '\n';
}

int main(int argc, char const *argv[])
{
	input();
	process();
	output();
	return 0;
}
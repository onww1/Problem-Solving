#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector <char> op;
vector <int> num;

int cal(int num1, char op, int num2) {
	if (op == '+') return num1 + num2;
	else if (op == '-') return num1 - num2;
	return num1 * num2;
}

void solve(int visited, int &mx) {
	if (visited == (1 << op.size()) - 1) {
		mx = max(mx, num[0]);
		return;
	}

	for (int i = 0; i < op.size(); ++i) {
		if ((visited & (1 << i)) == 0) {
			int tmp[2] = {num[i], num[i+1]};
			num[i] = num[i+1] = cal(num[i], op[i], num[i+1]);
			for (int j = i-1; j >= 0; --j) if ( visited & (1 << j) ) num[j] = num[i]; else break;
			for (int j = i+1; j < op.size(); ++j) if ( visited & (1 << j) ) num[j+1] = num[i]; else break;
			solve(visited | (1 << i), mx);
			num[i] = tmp[0]; num[i+1] = tmp[1];
			for (int j = i-1; j >= 0; --j) if ( visited & (1 << j) ) num[j] = tmp[0]; else break;
			for (int j = i+1; j < op.size(); ++j) if ( visited & (1 << j) ) num[j+1] = tmp[1]; else break;
		}
	}
}

char in[20];
int main(int argc, char *argv[]) {
	int n, i, mx = 1 << 31;
	scanf("%d %s", &n, in);
	for (i = 0; i < n; ++i) {
		if (i % 2) op.push_back(in[i]);
		else num.push_back(in[i] - '0');
	}	

	solve(0, mx);
	return !printf("%d\n", mx);
}
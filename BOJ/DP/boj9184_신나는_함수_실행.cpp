#include <iostream>
using namespace std;

int dp[21][21][21] = { 1, };
bool visited[21][21][21] = { true, false, };

int W(int A, int B, int C) {
	if(visited[A][B][C]) return dp[A][B][C];

	if (A <= 0 || B <= 0 || C <= 0)
		return dp[0][0][0];

	if (A > 20 || B > 20 || C > 20) {
		return dp[20][20][20] = W(20, 20, 20);
	}

	if (A < B && B < C) {
		visited[A][B][C] = true;
		return dp[A][B][C] = W(A, B, C-1) + W(A, B-1, C-1) - W(A, B-1, C);
	}

	visited[A][B][C] = true;
	return dp[A][B][C] = W(A-1, B, C) + W(A-1, B-1, C) + W(A-1, B, C-1) - W(A-1, B-1, C-1);
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int A, B, C;

	while( 1 ) {
		cin >> A >> B >> C;
		if( A == -1 && B == -1 && C == -1 ) break;
		cout << "w(" << A << ", " << B << ", " << C << ") = " << W(A, B, C) << '\n';
	}

	return 0;
}
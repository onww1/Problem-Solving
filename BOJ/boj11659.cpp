#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M, a, b, A[100001];
	cin >> N >> M;

	A[0] = 0;
	for (int i=1; i<=N; ++i) {
		cin >> A[i];
		A[i] += A[i-1];
	}

	for (int i=0; i<M; ++i) {
		cin >> a >> b;
		cout << (A[b] - A[a-1]) << '\n';
	}
	return 0;
}
#include <iostream>
using namespace std;

int A[200001], B[200001], IDX[200001];

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	for (int i=1; i<=N; ++i) {
		cin >> A[i];
		IDX[A[i]] = i;
	}

	for (int i=1; i<=N; ++i) {
		cin >> B[i];
	}

	int op, la, ra, lb, rb;
	while (M--) {
		cin >> op;
		if (op == 1) {
			cin >> la >> ra >> lb >> rb;
			int cnt = 0;
			for (int i=lb; i<=rb; ++i) {
				if (la <= IDX[B[i]] && IDX[B[i]] <= ra) cnt++;
			}
			cout << cnt << '\n';
		}
		else {
			cin >> la >> ra;
			swap(B[la], B[ra]);
		}
	}

	return 0;
}
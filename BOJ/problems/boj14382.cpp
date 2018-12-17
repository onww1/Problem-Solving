#include <iostream>
#include <vector>
using namespace std;

bool check(vector<bool>& chk) {
	bool isOK = true;
	for (int i=0; i<10; ++i) 
		isOK = isOK && chk[i];
	return isOK;
}

void process(vector<bool>& chk, int N) {
	while (N > 0) {
		chk[N%10] = true;
		N /= 10;
	}
}

void init(vector<bool>& chk) {
	for (int i=0; i<10; ++i) 
		chk[i] = false;
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T, N;
	vector<bool> chk(10);

	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		init(chk);

		cin >> N;
		if (N == 0) cout << "Case #" << tc << ": INSOMNIA" << '\n';
		else {
			int K = 0;
			while (!check(chk)) {
				K += N;
				process(chk, K);
			}
			cout << "Case #" << tc << ": " << K << '\n';
		}
	}

	return 0;
}
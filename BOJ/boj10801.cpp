#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int A[10], B, ca = 0, cb = 0;
	for (int i=0; i<10; ++i) cin >> A[i];
	for (int i=0; i<10; ++i) {
		cin >> B;
		if (A[i] > B) ca++;
		else if (A[i] < B) cb++;
	}
	if (ca > cb) cout << "A\n";
	else if (ca < cb) cout << "B\n";
	else cout << "D\n";

	return 0;
}
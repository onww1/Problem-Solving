#include <iostream>
using namespace std;

int y(int t) {
	return t/30 * 10 + 10;
}

int m(int t) {
	return t/60 * 15 + 15;
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	int y_sum = 0, m_sum = 0;
	int in;

	while (N--) {
		cin >> in;
		y_sum += y(in);
		m_sum += m(in);
	}

	if (y_sum < m_sum) cout << "Y " << y_sum << '\n';
	else if (y_sum > m_sum) cout << "M " << m_sum << '\n';
	else {
		cout << "Y M " << y_sum << '\n';
	}
	return 0;
}
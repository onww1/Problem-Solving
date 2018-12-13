#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int h, m, s, t;
	cin >> h >> m >> s >> t;
	s += t;
	m += s/60;
	s %= 60;
	h += m/60;
	m %= 60;
	h %= 24;
	cout << h << ' ' << m << ' ' << s << '\n';
	return 0;
}
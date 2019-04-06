#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;

	int h, m, a, d, dh, dm, da, dd;
	while(n--)
	{
		cin >> h >> m >> a >> d >> dh >> dm >> da >> dd;

		h += dh;
		m += dm;
		a += da;
		d += dd;

		if(h < 1) h = 1;
		if(m < 1) m = 1;
		if(a < 0) a = 0;

		int result = h + (5 * m) + (2 * a) + (2 * d);
		cout << result << '\n';
	}
	return 0;
}
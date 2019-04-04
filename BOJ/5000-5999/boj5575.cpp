#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int h1, m1, s1, h2, m2, s2;
	int rh, rm, rs;
	for(int i=0; i<3; i++)
	{
		cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
		rs = s2 - s1;
		if(rs < 0)
		{
			rs += 60;
			m2 -= 1;
		}
		rm = m2 - m1;
		if(rm < 0)
		{
			rm += 60;
			h2 -= 1;
		}
		rh = h2 - h1;

		cout << rh << " " << rm << " " << rs << '\n';
	}
	return 0;
}
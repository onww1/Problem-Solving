#include <iostream>
using namespace std;

int abs(int a)
{
	return a>0?a:(-a);
}

int getMinPathLength(int width, int pos1, int pos2)
{
	int val = abs(pos1 - pos2);
	return (val<width-val?val:width-val);
}

int main(int argc, char const *argv[])
{
	int t, n, m, r1, c1, r2, c2, res;
	cin >> t;
	for(int i=1; i<=t; i++)
	{
		cin >> n >> m >> r1 >> c1 >> r2 >> c2;
		res = getMinPathLength(n, r1, r2) + getMinPathLength(m, c1, c2);
		cout << "#" << i << " " << res << '\n';
	}
	return 0;
}
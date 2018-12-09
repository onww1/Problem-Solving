#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	long long r, c, n;
	cin >> r >> c >> n;
	long long cr = r/n + (r%n>0);
	long long cc = c/n + (c%n>0);
	cout << (cr * cc) << '\n';
	return 0;
}
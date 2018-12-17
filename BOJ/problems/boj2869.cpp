#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int A, B, V;
	cin >> A >> B >> V;
	int cnt = (V-A)/(A-B) + ((V-A)%(A-B) > 0);
	cout << (cnt + 1) << '\n';
	return 0;
}
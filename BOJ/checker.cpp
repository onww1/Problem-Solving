#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
	int cmp = strcmp(argv[1], argv[2]);
	if (cmp == 0) cout << "equal" << '\n';
	else cout << "not equal" << '\n';
	return 0;
}
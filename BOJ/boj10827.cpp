#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	string base_input;
	int exp, floating_pos = 0;

	cin >> base_input >> exp;
	vector<char> base(base_input.length() - 1);
	vector<char> res(base_input.length() * (exp + 1));
	int offset = 0;
	for (int i=base_input.length()-1; i>=0; i--) {
		if ('0' <= base_input[i] && base_input[i] <= '9') {
			base[i-offset] = res[i-offset] = base_input[i] - '0';
		}
		else {
			offset = 1;
			floating_pos = base_input.length() - 1 - i;
		}
	}

	floating_pos *= exp;
	int base_len = base_input.length();
	int res_len = base_input.length();
	int carry = 0;

	for (int i=2; i<=exp; ++i) {
		
	}

	return 0;
}
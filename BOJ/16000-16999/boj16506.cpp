#include <iostream>
#include <string>
using namespace std;

string get_opcode(string cmd) {
	if (cmd.compare("ADD") == 0) return string("00000");
	else if (cmd.compare("ADDC") == 0) return string("00001");
	else if (cmd.compare("SUB") == 0) return string("00010");
	else if (cmd.compare("SUBC") == 0) return string("00011");
	else if (cmd.compare("MOV") == 0) return string("00100");
	else if (cmd.compare("MOVC") == 0) return string("00101");
	else if (cmd.compare("AND") == 0) return string("00110");
	else if (cmd.compare("ANDC") == 0) return string("00111");
	else if (cmd.compare("OR") == 0) return string("01000");
	else if (cmd.compare("ORC") == 0) return string("01001");
	else if (cmd.compare("NOT") == 0) return string("01010");
	else if (cmd.compare("MULT") == 0) return string("01100");
	else if (cmd.compare("MULTC") == 0) return string("01101");
	else if (cmd.compare("LSFTL") == 0) return string("01110");
	else if (cmd.compare("LSFTLC") == 0) return string("01111");
	else if (cmd.compare("LSFTR") == 0) return string("10000");
	else if (cmd.compare("LSFTRC") == 0) return string("10001");
	else if (cmd.compare("ASFTR") == 0) return string("10010");
	else if (cmd.compare("ASFTRC") == 0) return string("10011");
	else if (cmd.compare("RL") == 0) return string("10100");
	else if (cmd.compare("RLC") == 0) return string("10101");
	else if (cmd.compare("RR") == 0) return string("10110");
	else if (cmd.compare("RRC") == 0) return string("10111");
	return NULL;
}

string get_3(int num) {
	if (num == 0) return string("000");
	else if (num == 1) return string("001");
	else if (num == 2) return string("010");
	else if (num == 3) return string("011");
	else if (num == 4) return string("100");
	else if (num == 5) return string("101");
	else if (num == 6) return string("110");
	else if (num == 7) return string("111");
	return NULL;
}

string get_4(int num) {
	if (num == 0) return string("0000");
	else if (num == 1) return string("0001");
	else if (num == 2) return string("0010");
	else if (num == 3) return string("0011");
	else if (num == 4) return string("0100");
	else if (num == 5) return string("0101");
	else if (num == 6) return string("0110");
	else if (num == 7) return string("0111");
	else if (num == 8) return string("1000");
	else if (num == 9) return string("1001");
	else if (num == 10) return string("1010");
	else if (num == 11) return string("1011");
	else if (num == 12) return string("1100");
	else if (num == 13) return string("1101");
	else if (num == 14) return string("1110");
	else if (num == 15) return string("1111");
	return NULL;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	string cmd;
	int a, b, c;

	while (n--) {
		cin >> cmd >> a >> b >> c;
		string res = get_opcode(cmd);
		res += string("0");
		res += get_3(a);
		res += get_3(b);
		if (cmd[cmd.length() - 1] == 'C') {
			res += get_4(c);
		}
		else {
			res += get_3(c);
			res += string("0");
		}
		cout << res << '\n';
	}

	return 0;
}
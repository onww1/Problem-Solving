#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	vector<string> vec;
	string input;
	while (true) {
		getline(cin, input);
		if (input.compare("0") == 0) break;
		vec.push_back(input);
	}

	string WHO, WHERE, WHAT;
	getline(cin, WHO);
	getline(cin, WHERE);
	getline(cin, WHAT);

	int len = WHERE.length();
	for (int i=0; i<len-2; i++) {
		if (WHERE[i] == 'W' && WHERE[i+1] == 'H' && WHERE[i+2] == 'O') {
			WHERE.erase(i, 3);
			WHERE.insert(i, WHO);
			len = WHERE.length();
		}
	}

	len = WHAT.length();
	for (int i=0; i<len-2; i++) {
		if (WHAT[i] == 'W' && WHAT[i+1] == 'H') {
			if (i < len-4 && WHAT[i+2] == 'E' && WHAT[i+3] == 'R' && WHAT[i+4] == 'E') {
				WHAT.erase(i, 5);
				WHAT.insert(i, WHERE);
				len = WHAT.length();
			}
			else if (WHAT[i+2] == 'O') {
				WHAT.erase(i, 3);
				WHAT.insert(i, WHO);
				len = WHAT.length();
			}
		}
	}

	int vec_size = vec.size();
	for (int st=0; st<vec_size; st++) {
		string& str = vec[st];
		len = str.length();
		for (int i=0; i<len-2; i++) {
			if (str[i] == 'W' && str[i+1] == 'H') {
				if (i < len-4 && str[i+2] == 'E' && str[i+3] == 'R' && str[i+4] == 'E') {
					str.erase(i, 5);
					str.insert(i, WHERE);
					len = str.length();
				}
				else if (i < len-3 && str[i+2] == 'A' && str[i+3] == 'T') {
					str.erase(i, 4);
					str.insert(i, WHAT);
					len = str.length();
				}
				else if (str[i+2] == 'O') {
					str.erase(i, 3);
					str.insert(i, WHO);
					len = str.length();
				}
			}
		}
		cout << str << '\n';
	}
	return 0;
}
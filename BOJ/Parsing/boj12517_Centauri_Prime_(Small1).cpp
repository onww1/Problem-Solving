#include <iostream>
#include <string>
using namespace std;

int judge(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
		c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
		return 2;
	else if (c == 'Y' || c == 'y')
		return 0;
	else 
		return 1;
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	string name;

	cin >> N;
	for (int i=1; i<=N; i++) {
		cin >> name;
		int who = judge(name[name.length()-1]);
		if ( who == 0 ) 
			cout << "Case #" << i << ": " << name << " is ruled by nobody.\n";
		else if ( who == 1 )
			cout << "Case #" << i << ": " << name << " is ruled by a king.\n";
		else if ( who == 2 )
			cout << "Case #" << i << ": " << name << " is ruled by a queen.\n";
	}
	return 0;
}
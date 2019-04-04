#include <iostream>
#include <vector>
using namespace std;

struct land {
	int id;
	char type;
	int num;
	vector<land> children;
};

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	land root;
	root.id = 1; root.type = 'S', root.num = 0;

	char type;
	int num;
	int next;

	return 0;
}
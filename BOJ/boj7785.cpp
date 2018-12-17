#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string name, status;
	unordered_set<string> set;
	int N;

	cin >> N;
	while (N--) {
		cin >> name >> status;
		if (!status.compare("enter")) {
			set.insert(name);
		}
		else {
			unordered_set<string>::const_iterator got = set.find(name);
			if (got != set.end()) set.erase(got);
		}
	}

	vector<string> enteredPeople(set.begin(), set.end());
	sort(enteredPeople.begin(), enteredPeople.end(), greater<string>());
	for (auto &it : enteredPeople)
		cout << it << '\n';
	return 0;
}
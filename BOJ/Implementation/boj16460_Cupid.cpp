#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string name, preference;
	int dist, N;
	cin >> name >> preference >> dist >> N;
	if (preference.compare("MF") == 0) 
		preference = string("FM");

	vector<string> candidate;
	int preferenceLen = preference.length();
	string dstname, dstpreference;
	int dstdist;
	for (int i=0; i<N; i++) {
		cin >> dstname >> dstpreference >> dstdist;
		if (dstdist <= dist) {
			if (preferenceLen == 2 || dstpreference.compare(preference) == 0) {
				candidate.push_back(dstname);
			}
		}
	}

	int len = candidate.size();
	if (len == 0) cout << "No one yet\n";
	else {
		sort(candidate.begin(), candidate.end());
		for (int i=0; i<len; i++) {
			cout << candidate[i] << '\n';
		}
	}
	return 0;
}
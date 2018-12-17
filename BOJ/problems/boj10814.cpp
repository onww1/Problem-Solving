#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct man {
	int age, idx;
	string name;
};

bool cmp(man a, man b) {
	if (a.age == b.age) return a.idx < b.idx;
	else return a.age < b.age;
}

int main() {
	int N;
	cin >> N;

	vector<man> v(N);

	for (int i=0; i<N; i++) {
		v[i].idx = i;
		cin >> v[i].age;
		getline(cin, v[i].name);
	}

	sort(v.begin(), v.end(), cmp);

	for (int i=0; i<N; i++) {
		cout << v[i].age << v[i].name << '\n';
	}

	return 0;
}
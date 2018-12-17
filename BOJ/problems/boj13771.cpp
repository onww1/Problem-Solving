#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct value {
	int a, b;
};

bool cmp(value a, value b) {
	if (a.a == b.a) return a.b < b.b;
	return a.a < b.a;
}

int main(int argc, char const *argv[])
{
	int n, a, b;
	vector<value> vec;

	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d.%d",&a, &b);
		vec.push_back({a, b});
	}

	sort(vec.begin(), vec.end(), cmp);
	printf("%d.%d\n", vec[1].a, vec[1].b);
	return 0;
}
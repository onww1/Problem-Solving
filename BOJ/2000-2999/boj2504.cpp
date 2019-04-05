#include <cstdio>
#include <vector>
using namespace std;

char in[31];
int main(int argc, char *argv[]) {
	scanf(" %s", in);
	vector <char> pstack;
	vector <int> nstack;

	int cur = 0;
	for (int i = 0; in[i]; ++i) {
		if (in[i] == '(' || in[i] == '[') {
			pstack.push_back(in[i]);
			nstack.push_back(cur);
			cur = 0;
		}
		else if (in[i] == ')') {
			if (!pstack.empty() && pstack.back() == '(') {
				if (cur == 0) cur = 2;
				else cur *= 2;
				cur += nstack.back();
				nstack.pop_back();
				pstack.pop_back();
			}
			else return !printf("0\n");
		}
		else {
			if (!pstack.empty() && pstack.back() == '[') {
				if (cur == 0) cur = 3;
				else cur *= 3;
				cur += nstack.back();
				nstack.pop_back();
				pstack.pop_back();
			}
			else return !printf("0\n");
		}
	}

	if (!pstack.empty()) return !printf("0\n");
	return !printf("%d\n", cur);
}


#include <cstdio>
#include <vector>
using namespace std;

char in[105];
vector <int> st;

int main() {
	scanf(" %s", in);
	for (int i = 0, a, b; in[i]; ++i) {
		if ('0' <= in[i] && in[i] <= '9') st.push_back(in[i] - '0');
		else if (in[i] == '+') {
			b = st.back(); st.pop_back();
			a = st.back(); st.pop_back();
			st.push_back(a + b);
		}
		else if (in[i] == '-') {
			b = st.back(); st.pop_back();
			a = st.back(); st.pop_back();
			st.push_back(a - b);	
		}
		else if (in[i] == '*') {
			b = st.back(); st.pop_back();
			a = st.back(); st.pop_back();
			st.push_back(a * b);	
		}
		else if (in[i] == '/') {
			b = st.back(); st.pop_back();
			a = st.back(); st.pop_back();
			st.push_back(a / b);	
		}
	}
	printf("%d\n", st.back());
	return 0;
}
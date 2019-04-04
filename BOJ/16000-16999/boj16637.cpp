#include <iostream>
#include <string>
#include <vector>
using namespace std;

int cal(int a, char op, int b) {
	if (op == '+') return a + b;
	else if (op == '-') return a - b;
	else if (op == '*') return a * b;
	else return a / b;
}

int atoi(char c) {
	return c-'0';
}

void solve(vector<int>& num, vector<char>& op, vector<bool>& paren, int& max) {
	int size = paren.size();
	
	if (size == op.size()) {
		int res = num[0];
		for (int i=0; i<size; i++) {
			if (i + 1 < size && paren[i + 1]) {
				res = cal(res, op[i], cal(num[i+1], op[i+1], num[i+2]));
				i++;
			} 
			else {
				res = cal(res, op[i], num[i+1]);
			}
		}
		max = res > max ? res : max;
		return;
	}

	if (!paren.empty() && !paren.back()) {
		paren.push_back(true);
		solve(num, op, paren, max);
		paren.pop_back();
	}

	paren.push_back(false);
	solve(num,op,paren,max);
	paren.pop_back();
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	string str;
	cin >> str;

	vector<int> num;
	vector<char> op;

	int len = str.length();
	for (int i=0; i<len; i++) {
		if (i % 2) op.push_back(str[i]);
		else num.push_back(atoi(str[i]));
	}

	vector<bool> paren;
	int max = -987654321;
	solve(num, op, paren, max);
	cout << max << '\n';
	return 0;
}
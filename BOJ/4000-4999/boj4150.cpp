#include <iostream>
#include <vector>
using namespace std;

void add(vector<char>& num1, vector<char>& num2, vector<char>& res) {
	int len1 = num1.size();
	int len2 = num2.size();
	int len = len1 > len2 ? len1 : len2;

	res.clear();
	res.resize(len + 1);
	int idx = 0;
	while (idx < len1 && idx < len2) {
		res[idx] += (num1[idx] + num2[idx]);
		res[idx + 1] = res[idx] / 10;
		res[idx] %= 10;
		idx++;
	}
	while (idx < len1) {
		res[idx] += num1[idx];
		res[idx + 1] = res[idx] / 10;
		res[idx] %= 10;
		idx++;
	}
	while (idx < len2) {
		res[idx] += num2[idx];
		res[idx + 1] = res[idx] / 10;
		res[idx] %= 10;
		idx++;
	}
	if (!res[len]) res.resize(len);
}

void print(vector<char> num) {
	int len = num.size();
	for (int i=len-1; i>=0; i--) {
		cout << (char)(num[i] + '0');
	}
	cout << '\n';
}

int main(int argc, char const *argv[])
{
	vector<char> num1, num2, num3;
	
	int N;
	cin >> N;

	num1.push_back(1);
	num2.push_back(1);
	num3.push_back(2);

	for (int i=4; i<=N; i++) {
		if (i % 3 == 1) add(num2, num3, num1);
		else if (i % 3 == 2) add(num3, num1, num2);
		else if (i % 3 == 0) add(num1, num2, num3);
	}

	if (N % 3 == 1) print(num1);
	else if (N % 3 == 2) print(num2);
	else if (N % 3 == 0) print(num3);

	return 0;
}
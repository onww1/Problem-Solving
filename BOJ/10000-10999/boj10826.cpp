#include <iostream>
#include <vector>
using namespace std;

void print(vector<char>& num) {
	int len = num.size();
	for (int i=len-1; i>=0; i--) {
		cout << (char)(num[i] + '0');
	}
	cout << '\n';
}

void bigSum(vector<char>& num1, vector<char>& num2, vector<char>& res) {

	int len1 = num1.size();
	int len2 = num2.size();
	int len = (len1 > len2 ? len1 : len2) + 1;
	res.clear();
	res.resize(len);

	int i=0;
	res[0] = 0;
	while (i < len1 && i < len2) {
		int a = num1[i];
		int b = num2[i];
		res[i + 1] = (res[i] + a + b)/10;
		res[i] = (res[i] + a + b)%10;
		i++;
	}

	while (i < len1) {
		int a = num1[i];
		res[i + 1] = (res[i] + a)/10;
		res[i] = (res[i] + a)%10;
		i++;
	}

	while (i < len2) {
		int a = num2[i];
		res[i + 1] = (res[i] + a)/10;
		res[i] = (res[i] + a)%10;
		i++;
	}

	if (res.back() == 0) 
		res.pop_back();
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<char> num1;
	vector<char> num2;
	vector<char> num3;

	num1.push_back(0);
	num2.push_back(1);
	num3.push_back(1);

	for (int i=3; i<=N; i++) {
		if ( i%3 == 0 ) 
			bigSum(num2, num3, num1);
		else if ( i%3 == 1 ) 
			bigSum(num3, num1, num2);
		else 
			bigSum(num1, num2, num3);
	}
	
	if ( N%3 == 0 ) print(num1);
	else if ( N%3 == 1 ) print(num2);
	else print(num3);

	return 0;
}
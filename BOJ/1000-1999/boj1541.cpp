#include <cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
	int sum = 0, num = 0;
	char op = 0;
	bool metMinus = false;

	scanf("%d", &num);
	sum += num;
	while (~scanf("%c", &op)) {
		if (op == '\n') break;
		scanf("%d", &num);
		if (metMinus) {
			sum -= num;
		}
		else {
			if (op == '+') sum += num;
			else {
				metMinus = true;
				sum -= num;
			}
		}
	}

	printf("%d\n", sum);
	return 0;
}
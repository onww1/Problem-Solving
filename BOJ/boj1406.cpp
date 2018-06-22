#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>

int main(void){
	char input[100001];
	scanf("%s", input);

	int n, size, ptr;
	std::vector<char> vec (input, input + strlen(input) );
	char command, c;

	size = ptr = strlen(input);

	scanf("%d", &n);
	while(n--){
		getchar();
		scanf("%c", &command);
		if(command == 'L'){
			if(ptr > 0) ptr--;
		} else if(command == 'D'){
			if(ptr < size) ptr++;
		} else if(command == 'B'){
			if(ptr == 0) continue;
			else vec.erase( vec.begin() + ptr - 1);
			size--;
			ptr--;
		} else if(command == 'P'){
			getchar();
			scanf("%c", &c);
			vec.insert( vec.begin() + ptr, c);
			ptr++;
			size++;
		}
	}

	auto endIdx = vec.end();
	for(auto it = vec.begin(); it != endIdx; it++){
		printf("%c", *it);
	}
	printf("\n");
	return 0;
}
#include <cstdio>
#include <cstring>

int main(void){
	int queue[10000];
	int head=0, tail=0, N, X;
	char command[6];
	scanf("%d", &N);

	for(int i=0; i<N; i++){
		scanf("%s", command);
		if(strcmp(command, "push") == 0){
			scanf("%d", &X);
			if(head == (tail+1)%10000) printf("queue is full\n");
			else{
				tail = (tail+1)%10000;
				queue[tail] = X;
			}
		} else if(strcmp(command, "pop") == 0){
			if(head == tail) printf("-1\n");
			else {
				head = (head+1)%10000;
				printf("%d\n", queue[head]);
			}
		} else if(strcmp(command, "size") == 0){
			if(tail < head) X = tail + 10000 - head;
			else X = tail - head;
			printf("%d\n", X);
		} else if(strcmp(command, "empty") == 0){
			if(head == tail) printf("1\n");
			else printf("0\n");
		} else if(strcmp(command, "front") == 0){
			if(head == tail) printf("-1\n");
			else printf("%d\n", queue[(head+1)%10000]);
		} else if(strcmp(command, "back") == 0){
			if(head == tail) printf("-1\n");
			else printf("%d\n", queue[tail]);
		} else printf("wrong command\n");
	}
	return 0;	
}
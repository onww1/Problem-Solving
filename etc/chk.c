#include <stdio.h>
#include <stdlib.h>
typedef int data;
struct elem{
	data d;
	struct elem *next;
};
typedef struct elem elem;
struct stack{
	int cnt;
	elem *top;
};
typedef struct stack stack;

void push(data d, stack *stk){
	elem *p;
	p = malloc(sizeof(elem));
	p->d = d;
	p->next = stk->top;
	stk->top = p;
	stk->cnt++;

	// elem *temp = stk->top;
	// while(temp != NULL){
	// 	printf("%d\n", temp->d);
	// 	temp = temp->next;
	// }
}

data pop(stack *stk){
	data d;
	elem *p;
	d = stk->top->d;
	p = stk->top;
	stk->top = stk->top->next;
	stk->cnt--;
	free(p);
	return d;
}

void print(stack *stk){
	elem *temp = stk->top;
	while(temp != NULL){
		printf("%d\n", temp->d);
		temp = temp->next;
	}
}

void initialize(stack *stk){
	stk->cnt = 0;
	stk->top = NULL;
}

int main(){
	char c;
	stack s;
	initialize(&s);
	while( scanf("%c", &c) != EOF ){
		if('0' <= c && c <= '9'){
			c = c - '0';
			push(c, &s);
		}
		else if(c == '+'){
			data a, b;
			a = pop(&s);
			b = pop(&s);
			push(a+b, &s);
		}
		else if(c == '-'){
			data a, b;
			a = pop(&s);
			b = pop(&s);
			push(b-a, &s);
		}
		else if(c == '*'){
			data a, b;
			a = pop(&s);
			b = pop(&s);
			push(a*b, &s);
		}
		else if(c == 'p'){
			print(&s);
		}
		else if(c == 'x'){
			break;
		}
	}
	printf("%d\n", pop(&s));
	return 0;
}

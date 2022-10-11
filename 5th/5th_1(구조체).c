#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_STACK_SIZE 100
typedef int element;				//int를 element로 재정의
typedef struct {
	element	stack[MAX_STACK_SIZE];	//1차원 배열로 스택 정의
	int top;						//stack 선언 
}Stack;
Stack s; 

int isEmpty(){
    if(s.top == -1) return 1;
    else return 0;
}
int isFull(){
    if(s.top == MAX_STACK_SIZE - 1) return 1;
    else return 0;
}	 
void push(element item){
    if (isFull()) return;
	s.top++;
    s.stack[s.top] = item;
}
element pop(){						//반환후 제거
	if (isEmpty()) return;
    element temp;
    temp = s.stack[s.top];
    s.top--;
    return temp;
}
element peek(){						//반환만
    return s.stack[s.top];
}
int main(){
    push(1);
	push(2);
	push(3);
	printf("%d\n",pop());
	printf("%d\n",peek());
	printf("%d\n",pop());
	return 0;
}
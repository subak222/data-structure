#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 5
typedef int element ;
typedef struct {
	element* data;
	int front;
	int rear;
	int size;
}Queue;
Queue* initQueue( int n );
int isFull( Queue *q );
void enQueue( Queue *q, element data );
int isEmpty( Queue *q );
element deQueue( Queue *q );
void destroyQueue( Queue * q );
void printAll( Queue *q );
int main() {
	Queue *q;
	element data;
	q = initQueue( 5 );
	enQueue( q, 10 ) ;  printAll(q);
	enQueue( q, 20 ) ;  printAll(q);
	enQueue( q, 30 ) ;  printAll(q);
	enQueue( q, 40 ) ;  printAll(q);
	enQueue( q, 50 ) ;  printAll(q);
	data = deQueue( q );    printAll(q);
	enQueue( q, 60 ) ;  printAll( q );
	destroyQueue( q );
	return 0;
}
Queue* initQueue( int n ){
	Queue* temp = (Queue*) malloc( sizeof(Queue) );
	temp -> size = n; // n을 크기로 하는 큐
	temp -> rear = -1;
	temp -> front = -1;
	temp -> data = (element *) malloc(sizeof(element) * n); // 크기 n 을 가지는 동적 배열 생성
	return temp;
}
int isFull( Queue *q ){
	return q->rear == q->size - 1;// 큐가 가득 차 있다면 rear 은 어떤 상태일까?
}
void enQueue( Queue *q, element data ){
	if(isFull(q)) {// 가득 차 있다면 "queue is full"이라고 출력
        printf("Queue is Full\n");
    }
    // 아니면 rear에 data 삽입
    else {
        q->rear++;
        q->data[q->rear] = data;
    }
}
int isEmpty( Queue *q ){
    return q->rear == q->front;// 큐가 비어 있따면 rear과 front 는 어떤 상태일까?
}
element deQueue( Queue *q ){
    if(isEmpty(q)){// 비어 있다면 "Queue is empty" 출력하고 0 리턴
        printf("Queue is Empty");
        return 0;
    }
    // 아니면 front위치의 데이터 리턴
    q->front++;
    element temp = q->data[q->front];
    return temp;
}
void printAll( Queue *q ){
    int i;
    for(i=0;i < QUEUE_SIZE;i++){
        if(i <= q->front || i > q->rear) {
            printf(" | ");
        }
        else {
            printf("%d | ", q->data[i]);
        }
    }
    printf("\n");
}

void destroyQueue( Queue * q ){
	free(q->data);// data 동적 메모리 해제
	free(q);// q 동적 메모리 해제
}
#include <iostream>
using namespace std;

const int StackSize = 2;
const int QueueSize = 5;

class Stack{
	private:
		char sarr[StackSize]; int top;
	public:
		Stack() {top = -1;}
		void PUSH(char val);
		char POP();
		void StackEmpty(){cout << "StackEmpty.\n";}
		void StackFull(){cout << "StackFull.\n";}
		void DisplayStack();
};
void Stack::PUSH(char val){
	if (top == StackSize - 1) StackFull();
	else sarr[++top] = val;
};
char Stack::POP(){
	if (top == -1) StackEmpty();
	else return sarr[top--];
};
void Stack::DisplayStack(){
	int sp; sp = top;
	while (sp != -1){cout << sarr[sp--] << " ";}
	cout << endl;
}; //Stack

class Queue{
	private:
		char qarr[QueueSize]; int front; int rear;
	public:
		Queue() {front = -1; rear = -1;}
		void ENQUE(char val);
		char DEQUE();
		void QueueFull() {cout << "QueueFull.\n";}
		void QueueEmpty() {cout << "QueueEmpty.\n";}
		void DisplayQ();
};
void Queue::ENQUE(char val){
	if (rear == QueueSize - 1) QueueFull();
	else qarr[++rear] = val;
};
char Queue::DEQUE(){
	if (front == rear) QueueEmpty();
	else return qarr[++front];
};
void Queue::DisplayQ(){
	int qp; qp = front + 1;
	while (qp <= rear){
		cout << qarr[qp] << " ";
		qp += 1;
	}
	cout << endl;
}; //Queue

class C_Queue{
	private:
		char cqarr[QueueSize]; int front; int rear; //int flag;
	public:
		C_Queue() {front = 0; rear = 0;}
		void C_Enque(char val);
		char C_Deque();
		void C_QueFull(){cout << "Queue is full.\n";}
		void C_QueEmpty(){cout << "Queue is empty.\n";}
		void DisplayC_Q();
};
void C_Queue::C_Enque(char val){
	if ((rear + 1) % QueueSize == front) C_QueFull();
	else {
		rear = (rear + 1) % QueueSize;
		cqarr[rear] = val;
	}
	/*
	if ((front == rear) && (flag == 1)) cout << "Queue is full.\n";
	else{
		cqarr[rear] = val;
		rear = (rear + 1) % QueueSize;
		flag = 1;
	}
	*/
};
char C_Queue::C_Deque(){
	if (front == rear) C_QueEmpty();
	else{
		front = (front + 1) % QueueSize;
		return cqarr[front];
	}
	/*	
	int item;
	if ((front == rear) && (flag == 0)){
		cout << "Queue is empty.\n";
	}
	else{
		item = cqarr[front];
		front = (front + 1) % QueueSize;
		flag = 0;
		return item;
	}
	*/
};
void C_Queue::DisplayC_Q(){
	int cqp = (front + 1) % QueueSize;
	while (cqp != (rear + 1 % QueueSize)){
		cout << cqarr[cqp] << " ";
		cqp = (cqp + 1) % QueueSize;
	}
	cout << endl;
};

int main(){
	Stack s;
	Queue q;
	C_Queue cq;
	
/*
	s.PUSH('a'); q.ENQUE('b'); q.ENQUE('c'); q.ENQUE('d'); s.PUSH('e');
	s.PUSH('F'); q.ENQUE('G');
	s.DisplayStack();
	q.DisplayQ();
	s.POP(); q.DEQUE(); q.DEQUE(); q.DEQUE(); s.POP();
	s.POP(); q.DEQUE();
*/
	/*
	s.PUSH(10); s.PUSH(20); s.DisplayStack();
	if(s.StackFull()) cout << "Stack is full" << endl;
	cout << "Pop: " << s.POP() << endl;
	cout << "Pop: " << s.POP() << endl;
	if(s.StackEmpty()) cout << "Stack is empty" << endl;

	q.ENQUE(10); q.ENQUE(20); q.ENQUE(30); q.DisplayQ();
	cout << "Deque : " << q.DEQUE() << endl;
	cout << "Deque : " << q.DEQUE() << endl;
	cout << "Deque : " << q.DEQUE() << endl;
	if(q.QueueEmpty()) cout << "Queue is empty" << endl;
	*/
/*
	cq.C_Enque('A'); cq.C_Enque('B'); cq.C_Enque('C'); cq.C_Deque(); cq.C_Enque('D');
	cq.DisplayC_Q();
	cq.C_Deque(); cq.C_Deque(); cq.C_Deque();
*/

	cq.C_Enque('A'); cq.C_Enque('B'); cq.C_Deque(); cq.C_Enque('C'); cq.C_Deque();
	cq.C_Deque(); cq.C_Enque('D'); cq.C_Enque('E'); cq.C_Deque(); cq.C_Enque('F');
	cq.C_Deque(); cq.C_Deque(); cq.C_Enque('G');
}

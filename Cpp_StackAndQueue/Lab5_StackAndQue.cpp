//20191644 이연주
#include <iostream>
using namespace std;

const int StackSize = 2;
const int QueueSize = 3;

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
	else cout << sarr[top--] << " ";
};
void Stack::DisplayStack(){
	int sp; 
	sp = top;
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
	else cout << qarr[++front] << " ";
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
		char cqarr[QueueSize]; int front; int rear; int flag;
	public:
		C_Queue() {front = 0; rear = 0;}
		void C_Enque(char val);
		char C_Deque();
		void DisplayC_Q();
};
void C_Queue::C_Enque(char val){
	if ((front == rear) && (flag == 1)) cout << "Queue full.\n";
	else{
		cqarr[rear] = val;
		rear = (rear + 1) % QueueSize;
		flag = 1;
	}
};
char C_Queue::C_Deque(){
	int item;
	if ((front == rear) && (flag == 0)){
		cout << "Queue empty.\n";
	}
	else{
		item = cqarr[front];
		front = (front + 1) % QueueSize;
		flag = 0;
		return item;
	}
};
void C_Queue::DisplayC_Q(){
	int cqp = front % QueueSize;
	int tf = 0;
	while (!tf){
		cout << cqarr[cqp] << " ";
		cqp = (cqp + 1) % QueueSize;
		if (cqp == rear % QueueSize) tf = 1;
	}
	cout << endl;
};

int main(){
	Stack s;
	Queue q;
	C_Queue cq;
	
	s.PUSH('a'); q.ENQUE('b'); q.ENQUE('c'); q.ENQUE('d'); s.PUSH('e');
	s.PUSH('F'); q.ENQUE('G');
	cout << " //2번 수행결과\n\n";

	cout << "Stack : "; s.DisplayStack(); 
	cout << "Queue : "; q.DisplayQ();
	cout << " //3, 4번 수행결과\n\n";

	cout << "Output : ";
	s.POP(); q.DEQUE(); q.DEQUE(); q.DEQUE(); s.POP();	
	cout << "\n //5번 수행결과\n\n";

	s.POP(); q.DEQUE();
	cout << " //6번 수행결과\n\n";

	cq.C_Enque('A'); cq.C_Enque('B'); cq.C_Enque('C'); cq.C_Deque(); cq.C_Enque('D');
	cq.DisplayC_Q();
	cout << " //8번 수행결과\n\n";

	cq.C_Deque(); cq.C_Deque(); cq.C_Deque(); cq.C_Deque();
	cout << " //9번 수행결과\n\n";
}

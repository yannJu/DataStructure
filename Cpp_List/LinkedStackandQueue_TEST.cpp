#include <iostream>
using namespace std;

//Node클래스
class Node{
	private:
		char data;
		Node *next;
		Node(char value){
			data = value;
			next = 0;
		}
		friend class List;
		/*friend class linkedStack;	
		friend class linkedQueue;	*/
};

//LinkedList Class
class List{
	private:
		Node *head, *front, *rear;
	public:
		List() {head = 0;}
		void createStack() {head = 0;}
		void createQueue() {front = 0; rear = 0;}
		~List();
		void Insert(char data);
		void displayList(); //ㅣist
		void push(char);
		char pop();
		void displayStack(); //stack
		void enqueue(char);
		char dequeue();
		void displayQueue(); //Queue
};

/*
linkedStack클래스
class linkedStack{
	private:
		Node *head;
	public:
		linkedStack() {head = 0;}
		~linkedStack();
		void createStack() {head = 0;}
		void push(char);
		char pop();
		int isEmpty();
		void searchStack(char);
		Node invert(Node head); 
};
*/

/*
linkedQue클래스
class linkedQueue{
	private:
		Node *front, *rear;
	public:
		linkedQueue() {front = 0; rear = 0;}
		~linkedQueue();
		void createQueue() {front = 0; rear = 0;}
		void enqueue(char);
		char dequeue();
		int isEmpty();
		void displayQueue();
		void searchQueue(char);
};
*/

int main(){
	List l1;
	List l2;
	List l3;
	
	l1.creatStack();
	l1.push('a'); l1.push('e');
	l1.displayStack();

	l2.createQueue();
	l2.enqueue('b'); l2.enqueue('c'); l2.enqueue('d');
	l2.displayQueue();
}

//linkedList 함수

void List::Insert(char data){
	Node *temp = new Node();
	temp->data = data;
	Node *p, *q;

	if (head == 0) head = temp;
	else if (temp->data < head->data) {
		temp->next = head;
		head = temp;
	}
	else {
		p = head;
		while ((p != 0) && (p->data < temp->data)){
			q = p;
			p = p->next;
		}
		if (p != 0){
			temp->next = p; q->next = temp;
		}
		else{
			q->next = temp;
		}
	}
}//Insert

bool List::isEmpty(){
	if (head == 0) {
		cout << "List is Empty.\n";
		return true;
	}
	else return false;
}//IsEmpty

void List::displayList(){
	Node *p;
	
	if (!isEmpty()){
		p = head;
		while(p){
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
	else cout << "List is empty!\n";
}//traverse = 모든 list의 값 출력

List::~List(){
	Node *p;
	while(head != 0){
		p = head;
		head = head->next;
		delete p;
	}
}//소멸자

//linkedStack 함수

linkedStack::~linkedStack(){
	Node *p;
	while (head != 0){
		p = head;
		head = head->next;
		delete p;
	}
}
void linkedStack::push(char data){
	Node *temp = new Node(data);
	
	if (isEmpty()) head = temp; //list가 비어있으면
	else {
		temp->next = head;
		head = temp;
	}
} //Stack Push

char linkedStack::pop(){
	Node *p; char num;

	num= head->data;
	p = head;
	head = head->next;
	delete p;

	return num;
} //Stack Pop

int linkedStack::isEmpty(){
	if (head == 0) return 1; //비어있으면 1
	else return 0;
} //Stack isEmpty

void linkedStack::displayStack(){
	Node *p;

	if (!isEmpty()){ //list가 비어있지않으면
		p = head;
		while(p){
			cout << p->data << " ";
			p = p->next;
		}
	}
	else cout << "Stack Empty.";
	cout << endl;
} //Stack displayStack

void linkedStack::searchStack(char data){
	Node *p;
	
	if(!isEmpty()){
		p = head;
		while(p != 0 && p->data != data) p = p->next;
		if (p) cout << p->data << " is in the list.";
		else cout << data << " is not in the list.";
	}
	else cout << "Stack Empty.";
	cout << endl;
} //Stack searchStack

/*Node linkedStack::invert(Node head){
	
}*/

//linkedQue함수
linkedQueue::~linkedQueue(){
	Node *p;
	
	while(front != 0){
		p = front;
		front = front->next;
		delete p;
	}
} //linkedQ의 소멸자

void linkedQueue::enqueue(char data){
	Node *temp = new Node(data);

	if (isEmpty()) {
		front = temp; rear = temp;
	}	
	else{
		rear->next = temp;
		rear = temp;
	}
} //linkedQ Enqueue

char linkedQueue::dequeue(){
	Node *p; char num;
	
	num = front->data;
	p = front;

	if (front == rear) {front = 0; rear = 0;}
	else front = front->next;

	delete p;
	return num;
} //linkedQ Dequeue

int linkedQueue::isEmpty(){
	if (front == 0) return 1;
	else return 0;
} //isEmpty

void linkedQueue::displayQueue(){
	Node *p;

	if (!isEmpty()){
		p = front;
		while (p) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
	else cout << "Queue Empty.\n";
} //linkedQ display

void linkedQueue::searchQueue(char data){
	Node *p;
	
	if (!isEmpty()){
		p = front;
		while(p != 0 && p->data != data) p = p->next;
		if (p) cout << p->data << " is in the list.\n";
		else cout << data << " is not in the list.\n";
	}
	else cout << "Queue Empty.\n";
} //linkedQ search

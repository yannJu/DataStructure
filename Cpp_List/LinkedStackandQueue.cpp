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
	public:
		char getData() {return data;}
		Node* getNext() {return next;}
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
		bool isEmpty();
		void displayList();
		void Concatenation(List, List); 
		void InvertList(); //ㅣist
		Node* getHead() {return head;}
		void push(char);
		char pop();
		void displayStack(); //stack
		void enqueue(char);
		char dequeue();
		void displayQueue(); 
		Node* getFront() {return front;} //Queue
};

int main(){
	List l1; //stack
	List l2; //queue
	List l3; //concat
	List l4; //invert with Stack
	List l5; //invert with List
	Node* temp;
	
	l1.createStack();
	l1.push('a'); l1.push('e');
	l1.displayStack();

	l2.createQueue();
	l2.enqueue('b'); l2.enqueue('c'); l2.enqueue('d');
	l2.displayQueue();

	l3.Concatenation(l1, l2);
	l3.displayList();

	l4.createStack();
	
	temp = l3.getHead();
	while(temp){
		l4.push(temp->getData());
		temp = temp->getNext();
	}
	l4.displayList();

	l3.InvertList();
}

//linkedList 함수
void List::Insert(char data){
	Node *temp = new Node(data);
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

void List::Concatenation(List ptr1, List ptr2){
	Node *temp;
	if (!ptr1.isEmpty()){
		temp = ptr1.getHead();
		while(temp){
			Insert(temp->getData());
			temp = temp->getNext();
		}
	}
	temp = ptr2.getFront();
	while(temp){
		Insert(temp->getData());
		temp = temp->getNext();
	}
} //Concat

void List::InvertList(){
	Node *current, *next = 0, *prev = 0;
	if (head != 0){
		current = head;
		while(current != 0){
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head = prev;
		displayList();
	}
}//InvertList = 거꾸로 모든노드 출력

List::~List(){
	Node *p;
	while(head != 0){
		p = head;
		head = head->next;
		delete p;
	}
}//소멸자

//Stack
void List::push(char data){
	Node *temp = new Node(data);
	
	if (head == 0) head = temp; //list가 비어있으면
	else {
		temp->next = head;
		head = temp;
	}
} //Stack Push

char List::pop(){
	Node *p; char num;

	num= head->data;
	p = head;
	head = head->next;
	delete p;

	return num;
} //Stack Pop

void List::displayStack(){
	Node *p;

	if (head != 0){ //list가 비어있지않으면
		p = head;
		while(p){
			cout << p->data << " ";
			p = p->next;
		}
	}
	else cout << "Stack Empty.";
	cout << endl;
} //Stack displayStack

//Que함수
void List::enqueue(char data){
	Node *temp = new Node(data);

	if (front == 0) {
		front = temp; rear = temp;
	}	
	else{
		rear->next = temp;
		rear = temp;
	}
} //linkedQ Enqueue

char List::dequeue(){
	Node *p; char num;
	
	num = front->data;
	p = front;

	if (front == rear) {front = 0; rear = 0;}
	else front = front->next;

	delete p;
	return num;
} //linkedQ Dequeue

void List::displayQueue(){
	Node *p;

	if (front != 0){
		p = front;
		while (p) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
	else cout << "Queue Empty.\n";
} //linkedQ display

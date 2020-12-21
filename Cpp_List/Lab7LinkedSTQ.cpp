//20191644이연주

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
		void createList() {head = 0;}
		void createStack() {head = 0;}
		void createQueue() {front = 0; rear = 0;}
		~List();
		void Insert(char data);
		bool isEmpty();
		void displayList();
		void Merge(List, List); 
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
	List l4; //invert with List
	Node* temp;
	int num = -1;
	char w;

	l1.createStack();
	l2.createQueue();
	
	while (num != 10){
		cout << "MENU : (1.Push 2.Pop 3.PrintST 4.Enque 5.Deque 6.PrintQ 7.Merge 8.Invert 9.PrintList 10.Quit) : ";
		cin >> num;
		cout << endl;

		switch (num){
			case 1: {
				cout << "Enter an integer to push = > ";
				cin >> w;
				l1.push(w);
				cout << endl;
				break;
			}
			case 2: {
				cout << l1.pop() << " ==> is popped! \n";
				break;
			}
			case 3: {
				cout << "Stack : ";
				l1.displayStack();
				break;
			}
			case 4: {
				cout << "Enter and integer to enque = > ";
				cin >> w;
				l2.enqueue(w);
				cout << endl;
				break;
			}
			case 5: {
				cout << l2.dequeue() << " ==> is dequed! \n";
				break;
			}
			case 6: {
				cout << "Queue : ";
				l2.displayQueue();
				break;
			}
			case 7: {
				l3.createList();
				l3.Merge(l1, l2);
				cout << "List :    ";
				l3.displayList();
				break;
			}
			case 8: {
				l3.InvertList();
				cout << "List :   ";
				l3.displayList();
				break;
			}
			case 9: {
				cout << "List :   ";
				l3.displayList();
				break;
			}
			case 10: {
				l1.~List();
				l2.~List();
				l3.~List();
				break;
			}
			default : {
				cout << "Input Wrong Num.\n";
				break;
			}
		}
	}
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

void List::Merge(List ptr1, List ptr2){
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
} //Merge

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

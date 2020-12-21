//20191644이연주
#include <iostream>
using namespace std;


class List{
	private:
		struct Node {
			int data;
			Node *next;
		}; //노드 struct
		Node *head;

	public:
		List() {head = 0;}
		~List();
		void Insert(int data);
		void Delete(int data);
		bool isEmpty();
		void Print();
		void Search(int num);
		void PrintLast();
		void PrintNth(int N);
};//LinkedList Class

void List::Insert(int data){
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

void List::Delete(int data){
	Node *p, *q;

	if (isEmpty()) return;
	if (head->data == data){
		p = head;
		head = head->next;
		delete p;
	}
	else {
		p = head;
		while (p != 0 && p->data != data){
			q = p;
			p = p->next;
		}
		if (p != 0){
			q->next = p->next;
			delete p;
		}
		else {
			cout << data << "is not in the list\n";
		}
	}	
}//Delete

bool List::isEmpty(){
	if (head == 0) {
		cout << "List is Empty.\n";
		return true;
	}
	else return false;
}//IsEmpty

void List::Print(){
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

void List::Search(int num){
	Node *p;

	if (!isEmpty()){
		p = head;
		while(p != 0 && p->data != num){
			p = p->next;
		}
		if (p) cout << p->data << "is found.\n";
		else cout << num << "is not in the list.\n";
	}
}//Search = 원하는 값이 있는지 확인

List::~List(){
	Node *p;
	while(head != 0){
		p = head;
		head = head->next;
		delete p;
	}
}//~List = 리스트 초기화

void List::PrintLast(){
	Node *p;
	if (!isEmpty()){
		p = head;
		while(p->next!= 0){
			p = p->next;
		}
		cout << "Last node : " << p->data << endl;
	}
}//PrintLast = List의 마지막 노드 출력

void List::PrintNth(int N){
	Node *p;
	if (!isEmpty()){
		p = head;
		cout << "\'" << N << "\'번째 노드 ";
		while(--N){
			if (p->next == 0) {
				cout << "Not Found.\n";
				return;
			}
			p = p->next;
		}
		cout << p->data << endl;	
	}
}//PrintNth = List의 N번째 노드 출력

int main(){
	List l1;
	int menu;
	int n;

	while(true){
		cout << "Command : 1.insert 2.delete 3.Search 4.PrintList 5.PrintLast 6.PrintNth 7.Quit >> \n";
		cin >> menu;
		switch(menu){
			case 1:
				cout << "Input a number >> \n";
				cin >> n;
				l1.Insert(n);
				break;
			case 2:
				cout << "Input a number >> \n";
				cin >> n;
				l1.Delete(n);
				break;
			case 3:
				cout << "Input a number >> \n";	
				cin >> n;
				l1.Search(n);
				break;
			case 4:
				l1.Print();
				break;
			case 5:
				l1.PrintLast();
				break;
			case 6:
				cout << "Enter Nth >> ";
				cin >> n;
				l1.PrintNth(n);
				break;
			case 7:
				l1.~List();
				break;
			default:
				cout << "값을 제대로 입력해주세요.\n";
				break;
		}
		if (menu == 7) break;
	}
}

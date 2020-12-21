#include <iostream>
using namespace std;

class Node{
	private:
		int data;
		string name;
		Node *next, *prev;
		Node (int val, string str) {
			data = val; name = str; next = 0; prev = 0;
		}
	friend class List;
}; //Node class

class List{
	private:
		Node *head;
	public:
		List() {head = 0;}
		//~List();
		void insertList(int, string);
		void deleteList(int);
		void forwardList();
		void backwardList();
		void searchList(int);
		int isEmpty() {return (head == 0);}
		int findNth(int);
		void insertAfterNth(int, int, string);
};

int main(){
	List l1;

	l1.insertList(153, "Lee");
	l1.insertList(175, "Yoon");
	l1.insertList(180, "Kim");
	l1.insertList(140, "Hong");
	l1.searchList(180);
	l1.forwardList();
	l1.deleteList(180);
	l1.backwardList();
}

void List::insertList(int data, string name){ //오름차순
	Node *temp = new Node(data, name);
	Node *p, *q;

	if (isEmpty()) head = temp;
	else if (temp->data < head->data){
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	else {
		p = head; q = head;
		while ((p != 0) && (p->data < temp->data)){
			q = p;
			p = p->next;
		}
		if (p) {
			temp->next = p;
			q->next = temp; p->prev = temp;
			temp->prev = q;
		}
		else {
			q->next = temp;
			temp->prev = q;
		}
	}
} //insert

void List::deleteList(int key){
	Node *p, *q;

	if (head->data == key){
		p = head;
		head = head->next; head->prev = 0;
		delete p;
	}
	else{
		p = head; q = head;
		while (p != 0 && p->data != key){
			q = p;
			p = p->next;
		}
		if (p) {
			q->next = p->next;
			if(p->next != 0) p->next->prev = q;
			delete p;
		}
		else cout << key << " is not in the list.\n";
	}
} //delete

void List::forwardList(){
	Node *p;
	
	if (!isEmpty()){
		p = head;
		cout << "----- Forward List -----\n";
		while(p) {
			cout << "Name : " << p->name << ", Height : " << p->data << endl;
			p = p->next;
		}
	}
	else cout << "List Empty!\n";
} //printForward

void List::backwardList(){
	Node *p;

	if (!isEmpty()){
		p = head;
		while (p->next) p = p->next;
		cout << "----- Backward List -----\n";		
		while (p) {
			cout << "Name : " << p->name << ", Height : " << p->data << endl;
			p = p->prev;
		}
	}
	else cout << "List Empty!\n";
}

void List::searchList(int key){
	Node *p;
	
	if (!isEmpty()){
		p = head;
		while (p != 0 && p->data != key) p = p->next;
		if (p) cout << p->data << " is in the list.\n";
		else cout << key << " is not in the list.\n";
	}
	else cout << "List Empty!\n";
}

//find nth insert after before!

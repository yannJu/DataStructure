#include <iostream>
using namespace std;

const int MaxSize = 7;

class Node{
	private:
		int data;
		Node *link = NULL;
		friend class Htable;
};

class Htable{
	private:
		Node *ht[MaxSize];
	public:
		Htable(){for (int i = 0; i < MaxSize; i++) ht[i] = NULL;}	
		int hash(int);
		int findkey(int);
		int insertkey(int);
		int deletekey(int);
		void printtable();
};

int main(){
	Htable h;
	char ch;
	int key;

	do {
		cout << "\nEnter command (i, f, d, q) :	";
		cin >> ch;
		if (ch != 'q'){
			cout << "Enter key :	";
			cin >> key;
			switch (ch){
				case 'i':
					if (h.insertkey(key) == 0) cout << "Cannot insert Key!\n"; break; 
				case 'f':
					if (h.findkey(key) == 0) cout << "Cannot find Key!\n"; 
					else cout << "key is found\n"; break;
				case 'd':
					if (h.deletekey(key) == 0) cout << "Cannot delete Key!\n"; break;
				default:
					cout << "Wrong Command!"; break;
			}
		}
		h.printtable();
	}while (ch != 'q');
}

int Htable::hash(int key){
	return (key % MaxSize);
}

int Htable::findkey(int key){
	int idx = hash(key);
	Node *p = ht[idx];
	if (p != NULL){
		Node *q = p;
		while (q != NULL && q->data != key) q = q->link;
		if (q == NULL) return 0;
		else return 1;
	}
	return 0;
}

int Htable::insertkey(int key){
	int idx = hash(key);
	Node *head = ht[idx];
	
	if (findkey(key) == 1) return 0;
	Node *p = new Node();
	p->data = key;
	
	if(head == NULL) ht[idx] = p;
	else {
		Node *q = head;
		while (q->link != NULL) q = q->link; 
		q->link = p;
	}
	return 1;
}

int Htable::deletekey(int key){
	int idx = hash(key);
	
	if (findkey(key) == 0) return 0;
	Node *p = ht[idx];
	Node *q;
	
	if (p->data == key){
		q = p;
		ht[idx] = q->link;
		delete p;
		return 1;
	}
	while(p->link!= NULL && p->data != key){
		 q = p; p = p->link;
	}
	q->link = p->link;
	cout << "Q : " << q->data << endl;
	delete p;
	return 1;
}

void Htable::printtable(){
	for (int i = 0; i < MaxSize; i++){
		cout << "Htable [" << i << "] : ";
		Node *p = ht[i];
		while(p != NULL) {
			cout << p->data;
			if (p->link != NULL) cout << " -> ";
			p = p->link;
		}
		cout << endl;
	}
}

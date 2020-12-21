#include <iostream>
using namespace std;

const int ArrSize = 16;
const int GraphSize = 6;
const int QueSize = 6;

class Node{
private:
	int data;
	Node *link;
	Node(int num) {data = num; link = NULL;}
friend class Tree;
};

class Tree{
private:
	Node *graph[GraphSize];
	bool visit[ArrSize];
	int Queue[QueSize];
	int front; int rear;
public:
	Tree();
	void insert(int p, int c);
	void bfs(int v);
	void initializeQ();
	void addQ(int v);	
	int deleteQ();
	void print_node();
};

Tree::Tree(){
	for (int i = 0; i < ArrSize; i++){
		visit[i] = false;
	}
	for (int i = 0; i < GraphSize; i++){
		Queue[i] = 0;
		graph[i] = NULL;
	}
	front = -1; rear = -1;
}
void Tree::insert(int p, int c){
	if (graph[p] == NULL){
		Node *tmp_P = new Node(p);
		graph[p] = tmp_P;
	}
	if (graph[c] == NULL){
		Node *tmp_C = new Node(c);
		graph[c] = tmp_C;
	}
	Node *P = graph[p];
	Node *C = new Node(c);
	while(P->link) P = P->link;
	P->link = C;
}
void Tree::bfs(int v){
	Node *p;	
	int bq;

	addQ(v); cout << "V" << v << " ";
	visit[v] = true;
	while(front != rear){
		bq = deleteQ();
		for (p = graph[bq]; p; p = p->link){
			if (!visit[p->data]){
				visit[p->data] = true;
				addQ(p->data); 
				cout << "V" << p->data << " ";
			}
		}
	}
}

void Tree::addQ(int v){
	if (rear == QueSize - 1) {
		cout << "Queue is Full.\n";
		return;
	}
	else Queue[++rear] = v;
}

int Tree::deleteQ(){
	if (front == rear) {
		cout << "Queue is Empty.\n";
		return -1;
	}
	else return Queue[++front];	
}

void Tree::print_node(){
	Node *p;
	for (int i = 0; i < GraphSize; i++){
		cout << "V" << i << " :	";
		for (p = graph[i]->link; p; p = p->link){
			cout << p->data << " ";
			if (p->link != NULL) cout << "-> ";
		}
		cout << endl;
	}
}

int main(){
	Tree t;
	int num1, num2;
	for (int i = 0; i < ArrSize; i++){
		cin >> num1 >> num2;
		t.insert(num1, num2);
	}
	cout << "1) Graph Data : \n";
	t.print_node();
	cout << "\n2) Breadth First Search(BFS) :\n";
	t.bfs(0);
	cout << endl;
}

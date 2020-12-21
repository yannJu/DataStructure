#include <iostream>
using namespace std;

const int ArrSize = 16;
const int GraphSize = 6;
const int QueSize = 6;

class Tree{
private:
	int graph[GraphSize][GraphSize];
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
	void print_matrix();
};

Tree::Tree(){
	for (int i = 0; i < ArrSize; i++){
		visit[i] = false;
	}
	for (int i = 0; i < GraphSize; i++){
		Queue[i] = 0;
		for (int j = 0; j < GraphSize; j++) graph[i][j] = 0;
	}
	front = -1; rear = -1;
}
void Tree::insert(int p, int c){
	graph[p][c] = 1;
}

void Tree::bfs(int v){
	int bq;

	addQ(v);
	visit[v] = true;
	while(front != rear){
		bq = deleteQ();
		for (int i = 0; i < GraphSize; i++){
			if ((!visit[i]) && (graph[bq][i] != 0)){
				visit[i] = true;
				addQ(i); 
				cout << "V" << i << " ";
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

void Tree::print_matrix(){
	cout << "	v0	v1	v2	v3	v4	v5	\n";
	for (int i = 0; i < GraphSize; i++){
		cout << "v" << i << "	";
		for (int j =0; j < GraphSize; j++){
			cout << graph[i][j] << "	";
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
	cout << "*****  Adjacent Matrix\n";
	t.print_matrix();
	cout << "*****	Breadth First Search(BFS) :	V0 ";
	t.bfs(0);
	cout << endl;
}

#include <iostream>
using namespace std;

const int GraphSize = 8;
const int QueSize = 8;

int graph1[8][8] = {
{0, 1, 1, 0, 0, 0, 0, 0},
{1, 0, 0, 1, 1, 0, 0, 0},
{1, 0, 0, 0, 0, 1, 1, 0},
{0, 1, 0, 0, 0, 0, 0, 1},
{0, 1, 0, 0, 0, 0, 0, 1},
{0, 0, 1, 0, 0, 0, 0, 1},
{0, 0, 1, 0, 0, 0, 0, 1},
{0, 0, 0, 1, 1, 1, 1, 0}
};

int graph2[6][6] = {
{0, 1, 1, 0, 0, 0},
{1, 0, 1, 1, 0, 0},
{1, 1, 0, 0, 0, 1},
{0, 1, 0, 0, 1, 1},
{0, 0, 0, 1, 0, 1},
{0, 0, 1, 1, 1, 0},
};

class Tree{
private:
	int graph[GraphSize][GraphSize];
	bool visit[GraphSize];
	int Queue[QueSize];
	int front; int rear;
public:
	Tree();
	void insert(int p, int c);
	void bfs(int v);
	void initializeQ();
	void addQ(int v);	
	int deleteQ();
	void print_matrix(int);
};

Tree::Tree(){
	for (int i = 0; i < GraphSize; i++){
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
				cout << i << " ";
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

void Tree::print_matrix(int graphsize){
	int cnt = 0;
	cout << "	";
	for (int i = 0; i < graphsize; i++) cout << "v" << i << "	";
	cout << endl;
	for (int i = 0; i < graphsize; i++){
		cout << "v" << i << "	";
		for (int j =0; j < graphsize; j++){
			cout << graph[i][j] << "	";
		}
		cout << endl;
	}
}

int main(){
	Tree t1;
	Tree t2;
	int num1, num2;
	
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			if (graph1[i][j] == 1) t1.insert(i, j);
		}
	}
	cout << "*****  Adjacent Matrix#1\n";
	t1.print_matrix(8);
	cout << "*****	Breadth First Search(BFS) :	0 ";
	t1.bfs(0);
	cout << endl;

	for (int i = 0; i < 6; i++){
		for (int j = 0; j < 6; j++){
			if (graph2[i][j] == 1) t2.insert(i, j);
		}
	}
	cout << "*****  Adjacent Matrix#2\n";
	t2.print_matrix(6);
	cout << "*****	Breadth First Search(BFS) :	0 ";
	t2.bfs(0);
	cout << endl;
}

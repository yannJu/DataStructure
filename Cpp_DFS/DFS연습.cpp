#include <iostream>
using namespace std;

const int ArrSize = 16;
const int GraphSize = 6;

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
public:
	Tree();
	void insert(int p, int c);
	void dfs(int v);
	void print_node();
};

Tree::Tree(){
	for (int i = 0; i < ArrSize; i++){
		visit[i] = false;
	}
	for (int i = 0; i < GraphSize; i++){
		graph[i] = NULL;
	}
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
	while (P->link != NULL) P = P->link;
	P->link = C;
}

void Tree::dfs(int v){
	Node *w;
	visit[v] = true;
	cout << "V" << v;
	for (w = graph[v]; w != NULL; w = w->link){
		if (!visit[w->data]) {
			cout << " -> ";
			dfs(w->data);
		}
	}
}

void Tree::print_node(){
	Node *w;
	for (int i = 0; i < GraphSize; i++){
		cout << "V" << i << " :   ";
		for (w = graph[i]->link; w != NULL; w = w->link){
			cout << w->data;
			if (w->link != NULL) cout << " -> ";
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
	cout << "\n2) Depth First Search Output (starting from v0)\n";
	t.dfs(0);
	cout << endl;
}

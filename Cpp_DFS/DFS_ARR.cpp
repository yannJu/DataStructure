#include <iostream>
using namespace std;

const int ArrSize = 16;
const int GraphSize = 6;

class Tree{
private:
	int graph[GraphSize][GraphSize];
	bool visit[ArrSize];
public:
	Tree();
	void insert(int p, int c);
	void dfs(int v);
	void print_matrix();
};

Tree::Tree(){
	for (int i = 0; i < ArrSize; i++){
		visit[i] = false;
	}
	for (int i = 0; i < GraphSize; i++){
		for (int j = 0; j < GraphSize; j++){
			graph[i][j] = 0;
		}
	}
}
void Tree::insert(int p, int c){
	graph[p][c] = 1;
}

void Tree::dfs(int v){
	visit[v] = true;
	cout << "V" << v << " ";
	for (int i = 0; i < GraphSize; i++){
		if (visit[i] == false && graph[v][i] == 1){
			dfs(i);
		}
	}

	
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
	cout << "*****	Depth First Search Output (starting from v0) :	";
	t.dfs(0);
	cout << endl;
}

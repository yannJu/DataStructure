#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX_ARY = 6;
int graph[MAX_ARY][MAX_ARY] = {
{0, 5, 100, 12, 100, 100},
{5,  0, 6, 10,24, 100},
{100, 6, 0, 17, 100, 30},
{12, 10, 17, 0, 20, 100},
{100, 24, 100, 20, 0, 13},
{100, 100, 30, 100, 13, 0}
};

char check[MAX_ARY] = {'A', 'B', 'C', 'D', 'E', 'F'};
int val[MAX_ARY] = {0,};

struct Cost{
	char begin;
	char end;
	int cost;
};

class Tree{
	private:
		int cost[MAX_ARY][MAX_ARY];
		int lowcost[MAX_ARY];
		Cost T[MAX_ARY];
		char TV[MAX_ARY];
	public:
		Tree();
		void insert(int begin, int end, int cost);
		int prim(char v, int c);
		int prim2(char v, int c);
		void prim_print();
		void print();
};

int main(){
	Tree t1;
	Tree t2;
	for (int i =0; i < MAX_ARY; i++){
		for (int j = 0; j < MAX_ARY; j++) {
			t1.insert(i, j, graph[i][j]);
			t2.insert(i, j, graph[i][j]);
		}
	}
	t1.print();
	t1.prim('A', 0);
	t1.prim_print();

	for (int i =0; i < MAX_ARY; i++) val[i] = 0;
	t2.prim2('A', 0);
	t2.prim_print();
}

Tree::Tree(){
	for (int i = 0; i < MAX_ARY; i++){
		for (int j = 0; j < MAX_ARY; j++){
			cost[i][j] = 999;
			val[j] = 0;
			lowcost[j] = 999;
		}
	}
	TV[0] = 'A';
}

void Tree::insert(int begin, int end, int cst){
	cost[begin][end] = cst;
}

int Tree::prim(char v, int c){
	int begin_idx, end_idx;
	int mincost = 999;
	int costCnt = c;

	for (int i = 0; i < MAX_ARY; i++){
		if (check[i] == v) begin_idx = i;
	} //char찾기 (노드이름)

	val[begin_idx] = 1; // 들어온 노드 방문표시

	for (int i = 0; i < MAX_ARY; i++){
		lowcost[i] = cost[begin_idx][i];
	} //배열 복사

	for (int i = 0; i < MAX_ARY; i++){
		if (val[i] == 0 && lowcost[i] > 0 && lowcost[i] < mincost) {
			mincost = lowcost[i]; end_idx = i;
		}
	}
	if (costCnt == MAX_ARY - 1) return costCnt;
	else {
		TV[costCnt + 1] = check[end_idx];
		T[costCnt].begin = check[begin_idx]; T[costCnt].end = check[end_idx]; T[costCnt].cost = mincost;
		costCnt += 1;
	}
	costCnt = prim(check[end_idx], costCnt);

	if (costCnt < MAX_ARY - 1) cout << "No spanning Tree.\n";
}

int Tree::prim2(char v, int c){
	int begin_idx, end_idx;
	int mincost = 999;
	int costCnt = c;

	for (int i = 0; i < MAX_ARY; i++){
		if (check[i] == v) begin_idx = i;
	} //char찾기 (노드이름)

	val[begin_idx] = 1; // 들어온 노드 방문표시
	
	for (int i =0; i < MAX_ARY; i++) {
		if (lowcost[i] > graph[begin_idx][i] && val[i] == 0){
			lowcost[i] = graph[begin_idx][i];
		}
	}

	if (costCnt == MAX_ARY - 1) return costCnt;
	else{
		for (int i =0; i < MAX_ARY; i++){
			if (graph[begin_idx][i] > 0 && graph[begin_idx][i] < mincost && val[i] == 0) {
				end_idx = i; mincost = graph[begin_idx][i];
			}
		}
		int idx = 0;
		for (int i =0; i < MAX_ARY; i++){
			if (graph[i][end_idx] == lowcost[end_idx]) idx = i;
		}
		cout << " ID X : " << idx << endl << endl;
		lowcost[idx] = 999;
		T[costCnt].cost = graph[idx][end_idx];
		T[costCnt].begin = check[idx]; T[costCnt].end = check[end_idx];
		val[idx] = 1;
	}
	costCnt = prim2(check[end_idx], ++costCnt);
}

void Tree::prim_print(){
	int cst = 0;

	cout << "MST :	";
	for (int i = 0; i < MAX_ARY - 1; i++){
		
		cout << "(" << T[i].begin << ", " << T[i].end << ")";
		if (i != MAX_ARY - 2) cout << " -> ";
		cst += T[i].cost;
	}
	cout << endl << "Weight : " << cst << endl;
}

void Tree::print(){
	cout << "	";
	for (int i = 0; i < MAX_ARY; i++) cout << check[i] << "	";
	cout << endl;
	for (int i =0; i < MAX_ARY; i++){
		cout << check[i] << "	";
		for (int j = 0; j < MAX_ARY; j++){
			cout << cost[i][j] << "	";
		}
		cout << endl;
	}
}

#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX_ARY = 6;
int graph[MAX_ARY][MAX_ARY] = {
{100, 6, 1, 5, 100, 100},
{6, 100, 4, 100, 3, 100},
{1, 4, 100, 5, 6, 5},
{5, 100, 5, 100, 100, 2},
{100, 3, 6, 100, 100, 6},
{100, 100, 5, 2, 6, 100}
};

int val[MAX_ARY] = {0,};

struct Cost{
	int begin;
	int end;
	int cost;
};

class Tree{
	private:
		int cost[MAX_ARY][MAX_ARY];
		int lowcost[MAX_ARY];
		Cost T[MAX_ARY];
		int TV[MAX_ARY];
	public:
		Tree();
		void insert(int begin, int end, int cost);
		int prim(int v, int c);
		int prim2(int v, int c);
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
	cout << "*****	Weighted Graph	*****\n\n";
	t1.print();
	cout << endl << "*****	Minimal Spanning Tree test1	*****\n\n";
	t1.prim(0, 0);
	t1.prim_print();

	for (int i =0; i < MAX_ARY; i++) val[i] = 0;
	cout << endl << "*****	Minimal Spanning Tree test2*****\n\n";
	t2.prim2(0, 0);
	t2.prim_print();
}

Tree::Tree(){
	for (int i = 0; i < MAX_ARY; i++){
		for (int j = 0; j < MAX_ARY; j++){
			cost[i][j] = 100;
			val[j] = 0;
			lowcost[j] = 100;
		}
	}
	TV[0] = 0;
}

void Tree::insert(int begin, int end, int cst){
	cost[begin][end] = cst;
}

int Tree::prim(int v, int c){
	int begin_idx = v, end_idx;
	int mincost = 100;
	int costCnt = c;

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
		TV[costCnt + 1] = end_idx;
		T[costCnt].begin = begin_idx; T[costCnt].end = end_idx; T[costCnt].cost = mincost;
		costCnt += 1;
	}
	costCnt = prim(end_idx, costCnt);

	if (costCnt < MAX_ARY - 1) cout << "No spanning Tree.\n";
}

int Tree::prim2(int v, int c){
	int begin_idx = v, end_idx;
	int mincost = 100;
	int costCnt = c;

	val[begin_idx] = 1; // 들어온 노드 방문표시
	
	for (int i =0; i < MAX_ARY; i++) {
		if (lowcost[i] > cost[begin_idx][i] && val[i] == 0){
			lowcost[i] = cost[begin_idx][i];
		}
	}

	if (costCnt == MAX_ARY - 1) return costCnt;
	else{
		for (int i =0; i < MAX_ARY; i++){
			if (cost[begin_idx][i] > 0 && cost[begin_idx][i] < mincost && val[i] == 0) {
				end_idx = i; mincost = cost[begin_idx][i];
			}
		}
		int idx = 0;
		for (int i =0; i < MAX_ARY; i++){
			if (cost[i][end_idx] == lowcost[end_idx]) idx = i;
		}
		lowcost[idx] = 100;
		T[costCnt].cost = cost[idx][end_idx];
		T[costCnt].begin = idx; T[costCnt].end = end_idx;
		val[idx] = 1;
	}
	costCnt = prim2(end_idx, ++costCnt);
}

void Tree::prim_print(){
	int cst = 0;

	for (int i = 0; i < MAX_ARY - 1; i++){
		cout << "V" << T[i].begin + 1 << ", V" << T[i].end + 1 << endl;
		cst += T[i].cost;
	}
	cout << endl << "Total = " << cst << endl;
}

void Tree::print(){
	cout << "	";
	for (int i = 1; i <= MAX_ARY; i++) cout << "v" << i << "	";
	cout << endl;
	for (int i =1; i <= MAX_ARY; i++){
		cout << "v" << i << "	";
		for (int j = 0; j < MAX_ARY; j++){
			cout << cost[i][j] << "	";
		}
		cout << endl;
	}
}
